#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void boobleSort(int *array, int tamanho){
    int i,j ,temp;
    for (i = 0; i < tamanho; i++){
        for(j = 0; j< tamanho-i-1;j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int quick(int *array ,int inicial, int final){
    int temp,j, i=inicial, pivot=array[final];
    for(j=inicial; j<final; j++){
        if(array[j] <= pivot){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    temp = array[i];
    array[i] = array[final];
    array[final] = temp;
    return i;
}

void quickSort(int *array ,int inicial, int final){
    int pivot;
    if(inicial < final){
        pivot = quick(array, inicial, final);
        quickSort(array, inicial, pivot-1);
        quickSort(array, pivot+1, final);
    }
}



void merge(int *array, int inicial, int meio, int final){
    int tamanhoDaEsquerda,tamanhoDaDireita, i ,topoDaEsquerda=0, topoDaDireita=0;
    int *vetorDaEsquerda, *vetorDaDireita;

    tamanhoDaEsquerda = meio-inicial +1;
    tamanhoDaDireita = final-meio;

    vetorDaEsquerda = (int *) malloc(tamanhoDaEsquerda * sizeof(int));
    vetorDaDireita = (int *) malloc(tamanhoDaDireita * sizeof(int));

    for (i = 0; i < tamanhoDaEsquerda; i++){
        vetorDaEsquerda[i] = *(array + inicial+ i);
    }
    for (i = 0; i < tamanhoDaDireita; i++){
        vetorDaDireita[i] = *(array + meio+1+ i);
    }
    for (i =inicial; i <= final; i++){
        if(topoDaEsquerda >= tamanhoDaEsquerda){
            array[i] = vetorDaDireita[topoDaDireita];
            topoDaDireita ++;
        }
        else if(topoDaDireita >= tamanhoDaDireita){
            array[i] = vetorDaEsquerda[topoDaEsquerda];
            topoDaEsquerda++;
        }
        else if(vetorDaEsquerda[topoDaEsquerda]< vetorDaDireita[topoDaDireita]){
            array[i] = vetorDaEsquerda[topoDaEsquerda];
            topoDaEsquerda++;
        }
        else{
            array[i] = vetorDaDireita[topoDaDireita];
            topoDaDireita++;
        }
    }
    free(vetorDaEsquerda);
    free(vetorDaDireita);
    
}


void mergeSort( int *array ,int inicial, int final){
    int meio;
    if(inicial < final){
        meio = (inicial + final)/2;
        mergeSort(array, inicial, meio);
        mergeSort(array, meio+1, final);
        merge(array, inicial, meio ,final);
    }
}

int main(int argc, char const *argv[]){
    int i, j=20,max=1000;
    int *vetorK;
    srand(time(NULL));
    vetorK = (int *) malloc (j*sizeof( int ));

    for (i = 0; i < j; i++){
        *(vetorK + i) = (rand()%(max+1));
    }
    for (i = 0; i < j; i++){
        printf("%d ", vetorK[i]);
    }
    printf("\n");
    printf("Virou:");
    printf("\n");
    quickSort(vetorK, 0,j-1);
    for (i = 0; i < j; i++){
        printf("%d ", vetorK[i]);
    }
    printf("\n");
    free(vetorK);
    return 0;
}
