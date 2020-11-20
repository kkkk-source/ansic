#include <stdio.h>

#define MAXLINE 15
#define NFOUND  0
#define FOUND   1

void squeeze (char s1[], char s2[]);

int
main ()
{
  char s1[] = "aeiou";
  char s2[] = "aei";
  squeeze (s1, s2);
  printf ("%s\n", s1);

  return 0;
}

void
squeeze (char s1[], char s2[])
{
  int i, j, k, state;

  for (i = k = 0; s1[i] != '\0'; i++)
    {
      state = !FOUND;
      for (j = 0; s2[j] != '\0'; j++)
	{
	  if (s1[i] == s2[j])
	    {
	      state = FOUND;
	      break;
	    }
	}
      if (state == !FOUND)
	s1[k++] = s1[i];
    }
  s1[k] = '\0';
}
