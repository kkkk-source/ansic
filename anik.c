#include <stdio.h>

int
anik (int times)
{
  char runes[5] = { '\\', '|', '/', '-', '\0' };
  int i, r;

  for (i = 0; i < times; i++)
    for (r = 0; r < 4; r++)
      printf ("\r %c \r", (char) runes[r]);
  fputs ("\n", stdout);
}
