#include <stdio.h>
#define DIM 10

int main(void){
    int i,numeros[DIM],maior=0,menor=32767,pares=0, soma=0,numeroProcurado;
    for(i=0; i<DIM;i++){
        printf("Por favor, digite o % dº numero: ", i+1);
        scanf("%d", &numeros[i]);
        if(numeros[i] > maior) maior=numeros[i];
        if(numeros[i] < menor) menor=numeros[i];
        if(numeros[i]%2 == 0) pares+=1;
        soma+=numeros[i];
    }
    printf("por valor, digite o numero que deseja procurar na lista: ");
    scanf("%d", &numeroProcurado);
    for(i=0; i<DIM;i++){
        if(numeros[i] == numeroProcurado){
            printf("O numero procurado (%d) existe na lista e está na posicao %d \n", numeroProcurado, i);
        }
    }
    printf("O maior valor da lista e:%d \n", maior);
    printf("O menor valor da lista e:%d \n", menor);
    printf("%d numeros dos digitados sao pares \n", pares);
    printf("a soma de valores e: %d \n", soma);
    return 0;
}