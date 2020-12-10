#include <stdio.h>
#define ALLOCSIZE 1000		/* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;	/* next free position */

char *
alloc (int n)			/* return pointer to n character */
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
    {				/* it fits */
      allocp += n;
      printf ("%ld\n", allocbuf + ALLOCSIZE - allocp);
      printf ("%s\n", allocbuf + ALLOCSIZE);
      return allocp - n;	/* old p */
    }
  else
    return 0;
}

void
afree (char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

int
main (void)
{
  char *s;
  s = alloc (5);
  s = alloc (10);
  s = alloc (15);
  afree (s);
  return 0;
}
