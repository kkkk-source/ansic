#include <stdio.h>

int main()
{
    return 0;
}

void detab(char to[], char from[], int tw)
{
    int i, j, l, blanks;
    char c;

    j = 0;
    for (i = 0; (c = from[i]) != '\0'; i++)
        if (c == '\t')
            for (l = 0; l < tw; l++)
                to[j++] = ' ';
        else
            to[j++] = c;
    to[j] = '\0';
}
