#include <stdio.h>
#include <string.h>

#define swap(t, x, y) \
{                     \
    t tmp;            \
    tmp = x;          \
    x = y;            \
    y = tmp;          \
}

int
main (void)
{
  int ai = 20, ib = 35;
  printf ("before swap: %d, %d\n", ai, ib);
  swap (int, ai, ib) printf ("after swap: %d, %d\n", ai, ib);
  return 0;
}
