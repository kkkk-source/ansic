#include <stdio.h>
#include <limits.h>

int
main ()
{
  printf ("Range of signed char is [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
  printf ("Range of unsigned char is [%d, %d]\n", 0, UCHAR_MAX);
  printf ("Range of char is [%d, %d]\n", CHAR_MIN, CHAR_MAX);

  printf ("Range of signed short int is [%hd, %hd]\n", SHRT_MIN, SHRT_MAX);
  printf ("Range of unsigned short int is [%hu, %hu]\n", 0, USHRT_MAX);

  printf ("Range of signed int is [%d, %d]\n", INT_MIN, INT_MAX);
  printf ("Range of unsigned int is [%u, %u]\n", 0, UINT_MAX);

  printf ("Range of signed long is [%ld, %ld]\n", LONG_MIN, LONG_MAX);
  printf ("Range of unsigned long is [%u, %lu]\n", 0, ULONG_MAX);

  return 0;
}
