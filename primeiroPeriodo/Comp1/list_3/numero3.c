/* 
Supondo que A, B e C são variáveis do tipo inteiro, com valores iguais a 5, 10 e -8, respectivamente,
uma variável D com valor de 1.5 e uma variável lógica L cujo valor é falso (= 0), quais os valores de X
obtidos nas expressões aritméticas apresentadas em seguida?
*/
#include <stdio.h>


    int main () {
        int x,y,z;
        x=y=10;
        z=++x; 
        x=-x; 
        y++; 
        x=x+y-(z--); 
        printf ("Valores de x %d, y %d e z %d\n", x, y, z);
        return 0;
}