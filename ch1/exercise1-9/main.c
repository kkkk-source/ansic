#include <stdio.h>

int main() 
{
    int c, b;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || b != ' ') {
            putchar(c);
        }
        b = c;
    }
    return 0;
}
