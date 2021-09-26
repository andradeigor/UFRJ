#include <stdio.h>

int main (void) {

    int var; /* var e um inteiro*/
    int *varPtr; /* varPtr e um ponteiro para inteiros*/
    
    var = 7;
    varPtr = &var ; /*varPtr aponta para onde esta var*/
    
    printf("O endereco de var e %p\n" /* ta printando o endereço de var*/
            "O valor de varPtr e %p\n", &var , varPtr ); 
            /*ta printando o endereço de varPtr,
             mas como ptr é ponteiro, o conteudo é o endereço de var*/

    printf("O valor de var e %d\n" /* o valor de var, diferente do primeiro que tinha o &*/ 
            "O valor que varPtr aponta e %d\n",/* o CONTEUDO de de varptr, com um * */
            var , *varPtr );
    
    /*Para os fortes*/
    printf("Mostrando que * e & sao complementares\n " 
                "&* varPtr = %p\n" 
                "*& varPtr =  %p\n" 
                ,&*varPtr , *&varPtr);

    return 0;

}