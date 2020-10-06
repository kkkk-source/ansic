#include <stdio.h>

/* print Celsius-Fahrenheit table 
    for celsius = 0, 5, ..., 50 */
int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 50;     /* upper limit */
    step = 5;       /* step size */

    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 5.0 / 9.0) + 32.0;
        printf("%2.0f\t%f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}


