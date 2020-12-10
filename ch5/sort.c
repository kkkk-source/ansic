#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max #lines to be sorted */
#define MAXLEN   1000		/* max length of any input line */

char *lineptr[MAXLINES];	/* pointres to text lines */

int getline (char *, int);
char *alloc (int);

int readlines (char *lineptr[], int nlines);
void writelines (char *lineptr[], int lines);

void qsort (char *lineptr[], int left, int right);

/* sort input lines */
int
main (void)
{
  int nlines;

  if ((nlines = readlines (lineptr, MAXLINES)) >= 0)
    {
      qsort (lineptr, 0, nlines - 1);
      writelines (lineptr, nlines);
      return 0;
    }
  else
    {
      printf ("error: input too big to sort\n");
      return 1;
    }
}

int
readlines (char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLINES];

  nlines = 0;
  while ((len = getline (line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc (len)) == NULL)
      return -1;
    else
      {
	line[len - 1] = '\0';
	strcpy (p, line);
	lineptr[nlines++] = p;
      }
  return nlines;
}

void
writelines (char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf ("%s\n", *lineptr++);
}
