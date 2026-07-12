#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// true if e exists in a
bool exists(int n, unsigned e, unsigned *a)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == e)
		{
			return true;
		}
	}
	return false;
}

// find the smallest int higher than e which is not in the array
unsigned next_value(int n, unsigned e, unsigned *a)
{
	do {
		e++;
	} while (exists(n, e, a));
	return e;
}

void permutations(int n)
{
	int k;
	unsigned a[n];
	k = 0;
	a[0] = 0;
	while (k >= 0)
	{
		a[k] = next_value(k, a[k], a);
		if (a[k] > n)
		{
			k--;
		}
		else if (k < n - 1)
		{
			a[++k] = 0;
		}
		else
		{
			output_array(n, a);
			k--;
		}
	}
}

void main(int argc, char **argv)
{
	int n;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n > 0)
		{
			permutations(n);
		}
	}
}
