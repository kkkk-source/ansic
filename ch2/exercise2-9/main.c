#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%d\n", bitcount(23));
    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; b++)
        x &= x - 1;
    return b;
}
