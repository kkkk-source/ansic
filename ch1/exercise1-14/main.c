#include <stdio.h>

#define SIZE 26

int
main ()
{
  int c, i;
  int mem[SIZE];

  for (i = 0; i < SIZE; i++)
    mem[i] = 0;

  while ((c = getchar ()) != EOF)
    if (c >= 'a' && c <= 'z')
      ++mem[c - 'a'];

  for (i = 0; i < SIZE; i++)
    printf ("%c | %2d\n", i + 'a', mem[i]);

  return 0;
}
