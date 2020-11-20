#include <stdio.h>
#include <ctype.h>

char[] htoi (const char line[]);

int
main ()
{
  char integer[] = "15";
  printf ("%s\n", htoi (integer));
  return 0;
}

char *
htoi (const char s[])
{
  int i, n;
  char hex[100];

  n = 0;
  for (i = 0; isdigit (s[i]); ++i)
    {
      n = 10 * n + (s[i] - '0');
    }
  sprintf (&hex, "0X%X\n", n);
  return hex;
}
