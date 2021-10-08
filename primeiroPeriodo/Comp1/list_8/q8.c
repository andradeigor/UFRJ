#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 50
typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

int merge(int *array, int comeco, int meio, int fim){
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;
    int *vetorEsquerda,*vetorDireita;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;
    vetorEsquerda = (int *) malloc (tamanhoEsquerda*sizeof( int ));
    vetorDireita = (int *) malloc (tamanhoDireita*sizeof( int )); 
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
    free(vetorEsquerda);
    free(vetorDireita);
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
    int i;
    TEMPO *tempos;
    tempos = ( TEMPO *) malloc ( sizeof (TEMPO)*DIM);
    srand(time(NULL));
    for(i=0;i<DIM;i++){
        (tempos + i) ->hora = rand()%60;
        (tempos + i) ->minuto = rand()%60;
        (tempos + i) ->segundo = rand()%60;
    }
    for ( i = 0; i < DIM; i++)
    {
        printf("%i = %d:%d:%d\n", i,(tempos+i)->hora,(tempos+i)->minuto,(tempos+i)->segundo);
    }
    
    return 0;
}