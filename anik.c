#include <stdio.h>

void
anik (void *arg)
{
  char runes[5] = { '\\', '|', '/', '-', '\0' };
  int r, *done;

  done = (int *) arg;
  while (*done == 0)
    for (r = 0; r < 4; r++)
      printf ("\r %c \r", runes[r]);
  fputs ("\n", stdout);
}
