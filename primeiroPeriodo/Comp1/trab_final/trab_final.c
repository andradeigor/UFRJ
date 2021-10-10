#include <stdio.h>
#include <stdlib.h>
#define DIM 7

typedef struct _PONTOS{
    char estadoAtual;
    int x,y;
} PONTOS;

void geraMatriz(PONTOS matriz[][DIM]){
    int i, j;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];

    /*transformando tudo em espaÃ§o*/
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = ' ';
            ((ponteiro+i*DIM)+ j)->x = j;
            ((ponteiro+i*DIM)+ j)->y = i;
        }
    }

    /*Cruz horizontal*/
    for(i=2; i<5; i++){
        for(j=0; j<DIM; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = 'o';
        }
    }

     /*Cruz vertical*/
    for(i=0; i<DIM; i++){
        for(j=2; j<5; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = 'o';
        }
    }

    /*Elemento do meio vazio*/
    ((ponteiro+3*DIM)+ 3)->estadoAtual = '.';
}

void printaMatriz(PONTOS matriz[][DIM], int selecionado[]){
    int i, j;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(j == selecionado[0] && i == selecionado[1]){
                printf("(%c)", ((ponteiro+i*DIM)+ j)->estadoAtual);
            }else{
                printf(" %c ", ((ponteiro+i*DIM)+ j)->estadoAtual);
            }
        }
        printf("\n");
    }
}

void printaCoordenadas(PONTOS matriz[][DIM]){
    int i,j;
    PONTOS *ponteiros;
    ponteiros = &matriz[0][0];
    for (i = 0; i < DIM; i++){
        for (j = 0; j < DIM; j++){
            printf("[%d,%d]", ((ponteiros + i *DIM)+j)->x,((ponteiros + i *DIM)+j)->y);
        }
    }
}

/*TABELA PROVISORIA:
  2 - Baixo
  4 - Esquerda 
  6 - Direita
  8 - Cima
  */

int podeMover(PONTOS matriz[][DIM], int x, int y, int direcao){
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    if(((ponteiro+y*DIM)+x)->estadoAtual != 'o') return 0;
    switch(direcao){
        case 2:
            if(((ponteiro+(y+1)*DIM)+x)->estadoAtual == 'o' && ((ponteiro+(y+2)*DIM)+x)->estadoAtual == '.' ){
                return 1;
            }
            break;
        case 4:
            if(((ponteiro+y*DIM)+(x-1))->estadoAtual == 'o' && ((ponteiro+y*DIM)+(x-2))->estadoAtual == '.' ){
                 return 1;
            }
            break;
        case 6:
            if(((ponteiro+y*DIM)+(x+1))->estadoAtual == 'o' && ((ponteiro+y*DIM)+(x+2))->estadoAtual == '.' ){
                return 1;
            }
            break;
        case 8:
            if(((ponteiro+(y-1)*DIM)+x)->estadoAtual == 'o' && ((ponteiro+(y-2)*DIM)+x)->estadoAtual == '.' ){
                return 1;
            }
            break;
        default: 
            return -1;
            break;
    }
    return -1;
}
int podeMoverTudo(PONTOS matriz[][DIM], int x, int y){
    int moves[4] = {2,4,6,8}, i, movimento;
    for(i=0; i<4; i++){
        movimento = podeMover(matriz, x, y, moves[i]);
        if(movimento) return 1;
    }
    return 0;
    
}
int verificaVitoria(PONTOS matriz[][DIM]){
    int x, y, bolinha = 0;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    for(y = 0; y < DIM; y++){
        for(x = 0; x < DIM; x++){
            if(((ponteiro+y*DIM)+x)->estadoAtual == 'o')bolinha++;
        }
    }
    if(bolinha == 1) return 1;
    return 0;
}

int verificaDerrota(PONTOS matriz[][DIM]){
    int x, y, pode;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];    
    for(y = 0; y < DIM; y++){
        for(x = 0; x < DIM; x++){
            if(((ponteiro+y*DIM)+x)->estadoAtual == 'o'){
                pode = podeMoverTudo(matriz, x, y);
                if(pode){
                    return 1;
                }
            }
        }
    }
    return 0;
}  

int main(){
    PONTOS matriz[DIM][DIM];
    int selecionado[2] = {3,5};
    int eValido, movimento;
    geraMatriz(matriz);
    while(1){
        printaMatriz(matriz, selecionado);
        printf("por favor, digite o movimento: ");
        movimento = (getchar() - 48);
        while(getchar() != '\n');
        eValido = podeMover(matriz,selecionado[0],selecionado[1],movimento);
        if(eValido==1){
            printf("MEU DEUS EU POSSO MOVER!!!!!\n");
        }
        else if (eValido==0){
            printf("ESSA NAO EU NAO CONSIGO ME MEXER!!!\n");
        }
        else printf("VOCE EH BURRO IRMAO? DIGITA UM COMANDO VALIDO!\n");
        if(verificaVitoria(matriz)){
           printf("Você ganhou!!!\n");
           return 1; 
        };
        if(!verificaDerrota(matriz)){
            printf("se fudeu\n");
            return 1;
        };
    }
    
    return 0;
}