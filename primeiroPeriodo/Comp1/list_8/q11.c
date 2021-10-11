#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _JOGADOR{
    int pontos;
    char nome[42];
} JOGADOR;

int comparaJogador(JOGADOR j1, JOGADOR j2){
    int maior=0;
    if (j1.pontos>j2.pontos){
        maior = 1;
    }else if(j1.pontos<j2.pontos){
        maior = -1;
    }
    return maior;
}
int merge(JOGADOR *array, int comeco, int meio, int fim){
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;
    JOGADOR *vetorEsquerda,*vetorDireita;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;
    vetorEsquerda = (JOGADOR *) malloc (tamanhoEsquerda*sizeof( JOGADOR ));
    vetorDireita = (JOGADOR *) malloc (tamanhoDireita*sizeof( JOGADOR )); 
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
    }
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
    }
    for(i=comeco;i<=(fim);i++){
        if(topoEsquerda <= tamanhoEsquerda){
            array[i] = vetorDireita[topoDireita];
            topoDireita ++;
        }
        else if(topoDireita <= tamanhoDireita){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else if(comparaJogador(vetorEsquerda[topoEsquerda],vetorDireita[topoDireita]) <0){
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

int mergeSort( JOGADOR *array, int comeco, int fim){
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
    int i,j;
    JOGADOR *jogadores;
    jogadores = ( JOGADOR *) malloc ( sizeof (JOGADOR)*DIM);

    for (i = 0; i < DIM; i++){
        printf("Por favor, digite o nome do jogador: ");
        fgets((jogadores + i)->nome, 42 ,stdin);
        for(j=0; j<42; j++){
            if((jogadores+i)->nome[j] == '\n' ||(jogadores+i) ->nome[j] == '\0') {
                (jogadores+i)->nome[j] = '\0';
                break;
            }
        }

        printf("Por favor, digite quantos pontos esse jogador tem: ");
        scanf("%d",&((jogadores + i)->pontos));
        while(getchar() != '\n');
    }
    mergeSort(jogadores,0,DIM-1);
    for (i = 0; i < DIM; i++){
        printf("o jogador %s teve %d pontos\n", (jogadores+i)->nome,(jogadores+i)->pontos);
    }
    

    return 0;
}