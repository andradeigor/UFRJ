#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _JOGADOR{
    int pontos;
    char nome[42];
} JOGADOR;

int main(){
    int i,j;
    JOGADOR *jogadores;
    jogadores = ( JOGADOR *) malloc ( sizeof (JOGADOR)*DIM);

    for (i = 0; i < DIM; i++){
        printf("Por favor, digite o nome do jogador: ");
        fgets((jogadores + i) ->nome, 42 ,stdin);
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
    for (i = 0; i < DIM; i++){
        printf("o jogador %s teve %d pontos\n", (jogadores+i)->nome,(jogadores+i)->pontos);
    }
    

    return 0;
}