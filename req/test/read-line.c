#include <stdio.h>
#define MAX_BUF_SIZE 256

int main(void)
{
    char buf[MAX_BUF_SIZE], c;
    int i;
    i = 0;
    while( (i < MAX_BUF_SIZE - 1) && (c = getchar()) != '\n')
        *(buf + i++) = c;
    *(buf + i) = '\0';

    return 0;
}


