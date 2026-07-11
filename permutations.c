#include <stdio.h>
#include <stdlib.h>

// print the array
void output_array(unsigned n, unsigned *a)
{
	unsigned i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// print all the arrays and free the memory
void output(unsigned m, unsigned n, unsigned **p)
{
	unsigned i, j;
	for (i = 0; i < m; i++)
	{
		output_array(n, p[i]);
		free(p[i]);
	}
	free(p);
}

unsigned factorial(unsigned n)
{
	unsigned i, f;
	f = 1;
	for (i = 2; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

// insert x at every position in a
unsigned** combine(unsigned n, unsigned x, unsigned *a)
{
	unsigned i, j, **b;
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

unsigned** permutations(unsigned m, unsigned n, unsigned *a)
{
	unsigned i, j, k, t, **c, **d, **e;
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
		return e;
	}
}

int main(int argc, char **argv)
{
	unsigned i, n, m, *a;
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
