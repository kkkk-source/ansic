#include <string.h>

void
reverse (char s[])
{
  int c, i, j;

  for (i = 0, j = strlen (s); i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}
