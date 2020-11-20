#include <stdio.h>

void expand (char s1[], char s2[]);

int
main ()
{
  char s1[] = "a-z";
  char s2[26];

  expand (s1, s2);
  printf ("%s\n", s2);
  return 0;
}

void
expand (char s1[], char s2[])
{
  int i, j, k, c;

  for (i = j = 0; (c = s1[i]) != '\0'; ++i)
    {
      if (s1[i + 1] == '-' && (c = s1[i + 2]) != '\0'
	  && ('a' <= s1[i] && s1[i] <= 'z' && s1[i] <= c && c <= 'z'))
	{
	  for (k = 0; k <= c - s1[i]; k++)
	    s2[j++] = s1[i] + k;
	  i += 2;
	}
      else
	{
	  s2[j++] = s1[i];
	}
    }
  s2[j] = '\0';
}
