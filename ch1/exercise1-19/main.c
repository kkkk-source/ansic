#include <stdio.h>
#define MAXLINE 1000

int get_line (char line[], int maxline);
void reverse (char line[], int length);

int
main ()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line (line, MAXLINE)) > 0)
    {
      reverse (line, len);
      printf ("%s\n", line);
    }
  return 0;
}

int
get_line (char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar ()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}


void
reverse (char s[], int lim)
{
  char temp;
  int i, j;

  j = lim - 1;
  for (i = 0; i < j; ++i, --j)
    {
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
    }

}
