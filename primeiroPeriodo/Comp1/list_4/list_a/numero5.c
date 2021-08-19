#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Os valores que recebi foram BEMMMMMM próximos, mudando somente da segunda casa decimal da porcentagem, bem preciso.
*/
int main(){
    int i, 
        n;
    float par=0.0,
        impar=0.0,
        porcentagempar=0.00,
        porcentagemimpar=0.00;

    srand(time(NULL));
    for (i=0; i<1000000; i++){
        n= rand();
        if(n%2 ==0){
            par +=1;
        }else{
            impar += 1;
        }
    }
    porcentagempar = (par/1000000.0)*100.0f;
    porcentagemimpar = (impar/1000000.0)*100.0f;
    printf("Foram encontrados %1.0f numeros pares e sua frequencia foi de  %1.2f \n",par,porcentagempar);
    printf("Foram encontrados %1.0f numeros impares e sua frequencia foi de  %1.2f \n",impar,porcentagemimpar);
    return 0;
}
