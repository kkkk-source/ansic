#include <stdio.h>

unsigned getbits (unsigned x, int p, int n);

int
main ()
{
  printf ("%b\n", getbits (5, 3, 1));
  return 0;
}

/* getbits: get n bits from position p */
unsigned
getbits (unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
