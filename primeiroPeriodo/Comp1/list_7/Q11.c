#include <stdio.h>

void misterio (char *n);

int main (void)
{
    char nome[41];
    gets (nome);
    misterio (nome);
    return 0;
}
    
void misterio (char *n)
{
    while (*n != ' ') n++;
    n ++;
    puts (n);
}