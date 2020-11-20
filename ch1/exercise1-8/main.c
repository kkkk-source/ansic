#include <stdio.h>

int
main ()
{
  long nb, nt, nn;
  int c;

  nb = 0;
  nt = 0;
  nn = 0;
  while ((c = getchar ()) != EOF)
    {
      if (c == ' ')
	{
	  ++nb;
	  continue;
	}
      if (c == '\t')
	{
	  ++nt;
	  continue;
	}
      if (c == '\n')
	{
	  ++nn;
	  continue;
	}
    }
  printf ("count blanks: %ld\tcount tabs: %ld\tcount newlines: %ld\n",
	  nb, nt, nn);
  return 0;
}
