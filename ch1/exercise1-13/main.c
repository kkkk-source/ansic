#include <stdio.h>

#define OUT  0
#define IN   1
#define SIZE 25

int main()
{
    int c, nc, i, state;
    int mem[SIZE];

    for (i = 1; i < SIZE; i++)
        mem[i] = 0;

    nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                ++mem[nc];
            }
            state = OUT;
            nc = 0;
        } else {
            state = IN;
            ++nc;
        }
    }

    for (i = 1; i < SIZE; i++)
        printf("%2d | %3d\n", i, mem[i]);

    return 0;
}
