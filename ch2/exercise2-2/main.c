#include <stdio.h>
#define MAXLINE 100

int main()
{
    char c, line[MAXLINE];
    int i = 0;

    while (i < MAXLINE - 1) {
        if ((c = getchar()) == '\n')
            break;
        if (c == EOF)
            break;
        line[i++] = c;
    }
    line[i] = '\0';
    printf("%s", line);
    return 0;
}
