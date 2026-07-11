#include <stdio.h>
#include <stdlib.h>

// print the array
void output_array(int n, int *a)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// print all the arrays and free the memory
void output(int m, int n, int** p)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		output_array(n, p[i]);
		free(p[i]);
	}
	free(p);
}

int factorial(int n)
{
	int i, f;
	f = 1;
	for (i = 2; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

// remove element at index j from array a
int* eliminate(int n, int j, int* a)
{
	int i, *b;
	b = malloc((n - 1) * sizeof(int));
	for (i = 0; i < j; i++)
	{
		b[i] = a[i];
	}
	for (i = j + 1; i < n; i++)
	{
		b[i - 1] = a[i];
	}
	return b;
}

// insert x at every position in a
int** combine(int n, int x, int* a)
{
	int i, j, **b;
	b = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		b[i] = malloc(n * sizeof(int));
		for (j = 0; j < i; j++)
		{
			b[i][j] = a[j];
		}
		b[i][i] = x;
		for (j = i + 1; j < n; j++)
		{
			b[i][j] = a[j - 1];
		}
	}
	return b;
}

int** permutations(int m, int n, int* a)
{
	int i, j, elem, k, t, w, **c, **d, **e;
	if (n <= 0)
	{
		return NULL;
	}
	else if (n == 1)
	{
		e = malloc(sizeof(int*));
		e[0] = a;
		return e;
	}
	else
	{
		e = malloc(m * sizeof(int*));
		w = 0;
		t = m / n;
		for (i = 0; i < n; i++)
		{
			elem = a[i];
			c = permutations(t, n - 1, eliminate(n, i, a));
			for (j = 0; j < t; j++)
			{
				d = combine(n, elem, c[j]);
				for (k = 0; k < n; k++)
				{
					e[w++] = d[k];
				}
			}
		}
		free(a);
		return e;
	}
}

int main(int argc, char **argv)
{
	int i, n, m;
	int* a;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n > 0)
		{
			a = malloc(n * sizeof(int));
			for (i = 0; i < n; i++)
			{
				a[i] = i + 1;
			}
			m = factorial(n);
			output(m, n, permutations(m, n, a));
		}
	}
}

//TODO: use unsigned int
