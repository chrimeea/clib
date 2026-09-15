#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print(int n, int *a)
{
  int i;
  printf("%d", a[0]);
  for (i = 1; i < n; i++)
  {
    printf(", %d", a[i]);
  }
  printf("\n");
}

void bubble(int n, int *a)
{
  bool k;
  int i, b;
  do
  {
    k = true;
    for (i = 1; i < n; i++)
    {
      if (a[i - 1] > a[i])
      {
        b = a[i];
        a[i] = a[i - 1];
        a[i - 1] = b;
        k = false;
      }
    }
  } while (!k);
}

void main(int argc, char **argv)
{
  int i, n, *a;
  if (argc == 1)
  {
    printf("Usage: %s 1 2 3...\n", argv[0]);
  }
  else
  {
    n = argc - 1;
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
      a[i] = atoi(argv[i + 1]);
    }
    bubble(n, a);
    print(n, a);
    free(a);
  }
}