#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i = 10 , j = 20;
    int temp ;
    int * p1 , * p2 ;
    p1 = &i; /* p1 recebe endereco de i */
    p2 = &j; /* p2 recebe endereco de j */
    temp = *p1; /* conteudo apontado por p1 para temp */
    *p1 = *p2; /* conteudo apontado por p2 para o apontado p1 ←֓ */
    *p2 = temp; /* conteudo apontado por p1 para p2 */
    /* O que sera impresso ???? */
    printf("%d %d\n", i , j);
    return 0;
}