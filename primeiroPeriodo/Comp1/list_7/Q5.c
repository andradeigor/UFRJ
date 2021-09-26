#include <stdio.h>

char * acheSobrenome (char nome []) {
    char *pnome ;
    int i = 0;
    while ( nome [i] != ' ') {
        i++;
    }
    i++;
    pnome = &nome[i];
    return pnome;
}




int main (void) {
    char nomeCompleto[80];
    char *p;

    puts (" Entre com o seu nome e um sobrenome.");
    gets(nomeCompleto);
    p = acheSobrenome(nomeCompleto);
    puts(p);
    return 0;
}