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

void printaMatriz(PONTOS matriz[][DIM], int selecionado[], int trocaEstado){
    int i, j;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(j == selecionado[0] && i == selecionado[1]){
                trocaEstado? printf("[%c]", ((ponteiro+i*DIM)+ j)->estadoAtual):printf("(%c)", ((ponteiro+i*DIM)+ j)->estadoAtual);
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

void movePeca(PONTOS matriz[][DIM],int* selecionado, int direcao){
    PONTOS* ponteiro;
    ponteiro = &matriz[0][0];
    
    switch (direcao)
    {
    case 2:
        (ponteiro+(*(selecionado+1)*DIM)+*(selecionado))->estadoAtual = '.';
        ((ponteiro+(*(selecionado +1)+1)*DIM)+*(selecionado))->estadoAtual = '.';
        ((ponteiro+(*(selecionado +1)+2)*DIM)+*(selecionado))->estadoAtual = 'o';
        *(selecionado+1) +=2; 
        break;
        
    case 4:
        (ponteiro+(*(selecionado +1)*DIM)+*(selecionado))->estadoAtual = '.';
        ((ponteiro+*(selecionado +1)*DIM)+(*(selecionado)-1))->estadoAtual = '.';
        ((ponteiro+*(selecionado +1)*DIM)+(*(selecionado)-2))->estadoAtual = 'o';
        *(selecionado) -=2; 
        break;
    
    case 6:
        (ponteiro+(*(selecionado +1)*DIM)+*(selecionado))->estadoAtual = '.';
        (ponteiro+(*(selecionado +1)*DIM)+(*(selecionado)+1))->estadoAtual = '.';
        (ponteiro+(*(selecionado +1)*DIM)+(*(selecionado)+2))->estadoAtual = 'o';
        *(selecionado) +=2;         
        break;
    case 8:  
        (ponteiro+(*(selecionado +1)*DIM)+*(selecionado))->estadoAtual = '.';
        ((ponteiro+(*(selecionado +1)-1)*DIM)+*(selecionado))->estadoAtual = '.';
        ((ponteiro+(*(selecionado +1)-2)*DIM)+*(selecionado))->estadoAtual = 'o';
        *(selecionado+1) -= 2;
        break;
    
    default:
        break;
    }
}


/*TABELA PROVISORIA:
  2 - Baixo
  4 - Esquerda 
  6 - Direita
  8 - Cima
  */

int podeMover(PONTOS matriz[][DIM], int *selecionado, int direcao){
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    if(((ponteiro+(*(selecionado+1))*DIM)+(*selecionado))->estadoAtual != 'o') printf("ISSO NEM EH UMA PECA, MALUCO!\n");;
    switch(direcao){
        case 2:
            if(((ponteiro+(*(selecionado+1)+1)*DIM)+(*selecionado))->estadoAtual == 'o' && ((ponteiro+(*(selecionado+1)+2)*DIM)+*selecionado)->estadoAtual == '.' ){
            movePeca(matriz, (selecionado), direcao);
            return 0;
            }
            break;
        case 4:
            if(((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)-1))->estadoAtual == 'o' && ((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)-2))->estadoAtual == '.' ){
            movePeca(matriz, (selecionado), direcao);
            return 0;
            }
            break;
        case 6:
            if(((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)+1))->estadoAtual == 'o' && ((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)+2))->estadoAtual == '.' ){
            movePeca(matriz, (selecionado), direcao);
            return 0;
            }
            break;
        case 8:
            if(((ponteiro+(*(selecionado+1)-1)*DIM)+*(selecionado))->estadoAtual == 'o' && ((ponteiro+(*(selecionado+1)-2)*DIM)+*(selecionado))->estadoAtual == '.' ){
            movePeca(matriz, (selecionado), direcao);
            return 0;
            }
            break;
        default: 
            printf("VOCE EH BURRO IRMAO? DIGITA UM COMANDO VALIDO!\n");
            break;
    }
    return 1;
}
int podeMoverTudo(PONTOS matriz[][DIM], int x, int y){
    int moves[4] = {2,4,6,8}, i, movimento;
    int *ponto;
    ponto = (int*) malloc(sizeof(int)*2);
    *(ponto) = x;
    *(ponto+1) = y;
    for(i=0; i<4; i++){
        movimento = podeMover(matriz, ponto, moves[i]);
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

void moveSelecionado(int *selecionado, int direcao){
        switch (direcao)
    {
    case 2:
        *(selecionado+1) +=1; 
        break;
        
    case 4:
        *(selecionado) -=1; 
        break;
    
    case 6:
        *(selecionado) +=1;         
        break;
    case 8:  
        *(selecionado+1) -= 1;
        break;
    
    default:
        break;
    }
}
int main(){
    PONTOS matriz[DIM][DIM];
    int selecionado[2] = {5,3};
    int direcao, trocaEstado = 0;
    geraMatriz(matriz);
    while(1){
        printaMatriz(matriz, selecionado, trocaEstado);
        if(trocaEstado){
             printf("Você está no modo de movimentar pecas.\n");
        }else{
             printf("Você está no modo de comer pecas.\n");
        }
        printf("por favor, digite o movimento: ");
        direcao = (getchar() - 48);
        while(getchar() != '\n');
        if(direcao == 65){
            if(trocaEstado){
                trocaEstado = 0;
            }else{
                trocaEstado = 1;
            }
        }
        if(trocaEstado){
            moveSelecionado(selecionado,direcao);
        }else{
            podeMover(matriz,selecionado,direcao);
        }
        printf("\033[1;1H\033[2J");
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