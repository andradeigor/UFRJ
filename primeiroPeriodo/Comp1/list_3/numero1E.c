/* 
Supondo que A, B e C são variáveis do tipo inteiro, com valores iguais a 5, 10 e -8, respectivamente,
uma variável D com valor de 1.5 e uma variável lógica L cujo valor é falso (= 0), quais os valores de X
obtidos nas expressões aritméticas apresentadas em seguida?
*/
#include <stdio.h>

int main(){
    int A=5,
    B=10,
    C=-8,
    L=0;
    float D=1.5;
    int X;
    X = A*C & (L|B);

    printf("o resultado é %d \n", X);
    return 0;
}