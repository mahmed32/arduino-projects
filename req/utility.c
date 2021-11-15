#include "defs.h"

void read_line(char* buf, int max_size)
{
    int i, c;
    i = 0;
    while( ( i < max_size - 1 ) && (c = getchar()) != '\n')
        *(buf + i++) = c;
    *(buf + i) = '\0';
    return;
}
void toggle_message(char* s)
{
    while( *s )
    {
        if(isalpha(*s))
            *s ^= ( 1 << 5 );/* toggle bit 5 */
        ++s;
    }
    return;
}
    
key_t Ftok(const char* path, int id)
{
    key_t res;

    if((res = ftok(path, id)) == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    return res;
}

int Msgget(key_t k, int f)
{
    int res;
    if((res = msgget( k, f )) == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    return res;
}
