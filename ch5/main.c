#include <stdio.h>
#define ALLOCSIZE 1000		/* size of available space */

static char allocbuf[ALLOCSIZE] = "hola";	/* storage for alloc */

int
main (void)			/* return pointer to n character */
{
  printf ("%s\n", allocbuf + 2);
  return 0;
}
