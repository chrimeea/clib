#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print the array
void output_array(int n, unsigned *a)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// print all the arrays and free the memory
void output(int m, int n, unsigned **p)
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

// insert e at every position in a
unsigned** combine(int n, unsigned e, unsigned *a)
{
	int i, j;
	unsigned **b;
	b = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		b[i] = malloc(n * sizeof(int));
		b[i][i] = e;
		memcpy(b[i], a, i * sizeof(int));
		memcpy(&b[i][i + 1], &a[i], (n - i - 1) * sizeof(int));
	}
	return b;
}

unsigned** permutations(int m, int n, unsigned *a)
{
	int i, j, k, t;
	unsigned **c, **d, **e;
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
		k = 0;
		t = m / n;
		c = permutations(t, n - 1, a);
		for (i = 0; i < t; i++)
		{
			d = combine(n, a[n - 1], c[i]);
			for (j = 0; j < n; j++)
			{
				e[k++] = d[j];
			}
		}
		free(c);
		return e;
	}
}

void main(int argc, char **argv)
{
	int i, n, m;
	unsigned *a;
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
			free(a);
		}
	}
}
