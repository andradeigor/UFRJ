#include <stdio.h>
#include <stdlib.h>

int merge(int *array, int comeco, int meio, int fim){
    /* os tamanhos serão calculados com base nos índices*/
    /* os topos apontarão para onde cada pilha está olhando*/
    int tamanhoEsquerda,tamanhoDireita,i;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;

    int vetorEsquerda[tamanhoEsquerda], 
    vetorDireita[tamanhoDireita];
    /*cria as subarrays com base no tamanho da lista original*/
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
        printf("e%d ", vetorEsquerda[i]);
    }
    printf("\n");
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
        printf("d%d ", vetorDireita[i]);
    }
    printf("\n");
    return 0;
}

int mergeSort( int *array, int comeco, int fim){
    int meio;
    if(fim-comeco>1){
        meio = (comeco+fim)/2;
        mergeSort(array,comeco,meio);
        mergeSort(array,meio,fim);
        merge(array, comeco, meio, fim);
    }
    return 0;
}


int main(){
    int array[10] = {0,5,4,3,2,10,15,11,23,12,};
    mergeSort(array, 0, 9);
    printf("\n");
    return 0;
}
