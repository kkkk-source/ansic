#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float fToC(float fahr);

int main()
{
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3.f\t%3.2f\n", fahr, fToC(fahr));
    return 0;
}

float fToC(float fahr) 
{
    return 5.0 / 9.0 * (fahr - 32.0);
}
