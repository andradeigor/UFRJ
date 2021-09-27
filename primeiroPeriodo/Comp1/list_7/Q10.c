#include <stdio.h>
#include <stdlib.h>

int merge(int *array, int comeco, int meio, int fim){
    /* os tamanhos serão calculados com base nos índices*/
    /* os topos apontarão para onde cada pilha está olhando*/
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;

    int vetorEsquerda[tamanhoEsquerda], 
    vetorDireita[tamanhoDireita];
    /*cria as subarrays com base no tamanho da lista original*/
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
    }
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
    }
    for(i=comeco;i<=(fim);i++){
        if(topoEsquerda >= tamanhoEsquerda){
            array[i] = vetorDireita[topoDireita];
            topoDireita ++;
        }
        else if(topoDireita >= tamanhoDireita){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else if(vetorEsquerda[topoEsquerda]< vetorDireita[topoDireita]){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else{
            array[i] = vetorDireita[topoDireita];
            topoDireita++;
        }
    }
    return 0;
}

int mergeSort( int *array, int comeco, int fim){
    int meio;
    if(comeco<fim){
        meio = (comeco+fim)/2;
        mergeSort(array,comeco,meio);
        mergeSort(array,meio+1,fim);
        merge(array, comeco, meio, fim);
    }
    return 0;
}


int main(){
    int i,array[10] = {0,5,4,3,2,10,15,11,23,12};
    mergeSort(array, 0, 9);
    for(i=0;i<10;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
