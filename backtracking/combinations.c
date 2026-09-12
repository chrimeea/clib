#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

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
  do
    {
      e++;
    } while (exists(n, e, a));
  return e;
}

void combinations(int n, int k)
{
  int i;
  unsigned a[k];
  i = 0;
  a[0] = 0;
  while (i >= 0)
    {
      a[i] = next_value(i, a[i], a);
      if (a[i] > n)
	{
	  i--;
	}
      else if (i < k - 1)
	{
	  a[++i] = 0;
	}
      else
	{
	  output_array(k, a);
	  if (n == k)
	    {
	      // optimization for permutations
	      i--;
	    }
	}
    }
}

void arrangements(int n)
{
  int i;
  for (i = 1; i <= n; i++)
    {
      combinations(n, i);
    }
}

void permutations(int n)
{
  combinations(n, n);
}

void main(int argc, char **argv)
{
  int n, m, opt, c = 2;
  while ((opt = getopt(argc, argv, "pac")) != -1)
    {
      switch (opt)
	{
	case 'p':
	  c = 1;
	  break;
	case 'a':
	  c = 2;
	  break;
	case 'c':
	  c = 3;
	  break;
	default:
	  fprintf(stderr, "Usage: %s [-p][-a][-c] n [k]\n", argv[0]);
	  fprintf(stderr, "%4s%s\n", "-p", "  permutations");
	  fprintf(stderr, "%4s%s\n", "-a", "  arrangements");
	  fprintf(stderr, "%4s%s\n", "-c", "  combinations");
	  exit(EXIT_FAILURE);
	}
    }
  if (optind >= argc)
    {
      fprintf(stderr, "Missing argument m, n\n");
      exit(EXIT_FAILURE);
    }
  n = atoi(argv[optind]);
  if (n > 0)
    {
      if (c == 1)
	{
	  permutations(n);
	}
      else if (c == 2)
	{
	  arrangements(n);
	}
      else if (c == 3 && optind + 1 < argc)
	{
	  m = atoi(argv[optind + 1]);
	  if (n >= m && m > 0)
	    {
	      combinations(n, m);
	    }
	}
    }
}

