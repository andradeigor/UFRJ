/* 
Supondo que A, B e C são variáveis do tipo inteiro, com valores iguais a 5, 10 e -8, respectivamente,
uma variável D com valor de 1.5 e uma variável lógica L cujo valor é falso (= 0), quais os valores de X
obtidos nas expressões aritméticas apresentadas em seguida?
*/
#include <stdio.h>

int main(){
    int X;
    X = (11 > 2 ) && (5 > 30);

    printf("o resultado é %d \n", X);
    return 0;
}