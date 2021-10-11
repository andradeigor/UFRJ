/*
Complete o programa anterior, definindo uma função que realoca uma área de memória “limpa” para string de caracteres, 
cujo tamanho é o dobro do tamanho passado como argumento, a partir do endereço da área alocada por areaAlocada, 
retornando o endereço inicial dessa área.
*/

#include <stdio.h>
#include <stdlib.h>



int main (void){
char *a, *b; 
   a = "auva"; 
   b = "abacate"; 

   if (*a < *b) printf ("%s vem antes de %s no dicionário\n", a, b); 
   else printf ("%s vem depois de %s no dicionário\n", a, b);

}
