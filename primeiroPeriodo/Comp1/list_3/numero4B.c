/* 
Supondo que A, B e C são variáveis do tipo inteiro, com valores iguais a 5, 10 e -8, respectivamente,
uma variável D com valor de 1.5 e uma variável lógica L cujo valor é falso (= 0), quais os valores de X
obtidos nas expressões aritméticas apresentadas em seguida?
*/
#include <stdio.h>


    int main () {
        int y=2,a=8,c=12;
        float x=6.0, z=4.0, b=7.5;
        float result;
        result = x - y * a > c % y;
        printf ("O resultado é %f \n", result);
        return 0;
}