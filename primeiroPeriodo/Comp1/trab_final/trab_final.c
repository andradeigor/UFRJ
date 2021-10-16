#include <stdio.h>
#include <stdlib.h>
#define DIM 7

typedef struct _PONTOS{
    char estadoAtual;
    int x,y;
} PONTOS;




int podeMover(PONTOS matriz[][DIM], int *selecionado, int direcao){
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    if(((ponteiro+(*(selecionado+1))*DIM)+(*selecionado))->estadoAtual != 'o') {
        printf("ISSO NEM EH UMA PECA, MALUCO!\n");
        return 1;
    }
    switch(direcao){
        case 2:
            if(((ponteiro+(*(selecionado+1)+1)*DIM)+(*selecionado))->estadoAtual == 'o' && ((ponteiro+(*(selecionado+1)+2)*DIM)+*selecionado)->estadoAtual == '.' ){
                return 0;
            }
            break;
        case 4:
            if(((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)-1))->estadoAtual == 'o' && ((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)-2))->estadoAtual == '.' ){
                return 0;
            }
            break;
        case 6:
            if(((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)+1))->estadoAtual == 'o' && ((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)+2))->estadoAtual == '.' ){
                return 0;
            }
            break;
        case 8:
            if(((ponteiro+(*(selecionado+1)-1)*DIM)+*(selecionado))->estadoAtual == 'o' && ((ponteiro+(*(selecionado+1)-2)*DIM)+*(selecionado))->estadoAtual == '.' ){
                return 0;
            }
            break;
        default: 
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
        if(!movimento) return 1;
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

void moveSelecionadoMultiplo(PONTOS matriz[][7], int *selecionado, char *movimentos, int tamanho){
    int i;
    char* ponteiro = movimentos;
    PONTOS *endereco = &matriz[0][0];
    for(i=0; i<tamanho; i++){
        if(*(ponteiro+i) == '\0') break;
        switch(*(ponteiro+i)){
            case '2':
                if((endereco + ((*(selecionado+1)+1)*DIM) + *(selecionado))->estadoAtual == '.' || (endereco+((*(selecionado+1)+1)*DIM)+ *(selecionado))->estadoAtual == 'o') *(selecionado+1) += 1;
                break;
            case '4':
                if((endereco+(*(selecionado+1)*DIM)+ (*(selecionado)-1))->estadoAtual == '.' || (endereco+(*(selecionado+1)*DIM)+ (*(selecionado)-1))->estadoAtual == 'o') *(selecionado) -= 1;
                break;
            case '6':
                if((endereco+(*(selecionado+1)*DIM)+ (*(selecionado)+1))->estadoAtual == '.' || (endereco+(*(selecionado+1)*DIM)+ (*(selecionado)+1))->estadoAtual == 'o') *(selecionado) += 1;
                break;
            case '8':
                if((endereco+((*(selecionado+1)-1)*DIM)+ *(selecionado))->estadoAtual == '.' || (endereco+((*(selecionado+1)-1)*DIM)+ *(selecionado))->estadoAtual == 'o') *(selecionado+1) -= 1;
                break;
        }
    }

}
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
int CarregaJogo(FILE *movimento, PONTOS matriz[][DIM], int *selecionado){
    int letra,movimentoValido, i;
    char movimentos[13];
    letra = fgetc(movimento);
    if(letra ==EOF){
        printf("Não há jogos salvos, favor começar um novo!\n");
        return 1;   
    }
    while(letra !=EOF){
        
        if(letra =='q'){
            i=0;
            while(letra!='\n'){
                letra = fgetc(movimento);
                movimentos[i] = letra;
                i++;

            }
            movimentos[i+1] = '\0';
            printf("%s", movimentos);
            moveSelecionadoMultiplo(matriz,selecionado,movimentos,13);
        }else{
            printf("letra normal %d\n", letra-48);
            movimentoValido = podeMover(matriz,selecionado,letra - 48);
            if(!movimentoValido){
                movePeca(matriz, (selecionado), letra - 48);
            }
            
        }
            letra = fgetc(movimento);
    }
    return 0;
}

int main(){
    PONTOS matriz[DIM][DIM];
    FILE *arquivo;
    int selecionado[2] = {5,3};
    int direcao, trocaEstado = 0, 
    estadoDoJogo, canMove,escolha;
    char movimentos[13];

    geraMatriz(matriz);

    arquivo = fopen("movimentos.txt", "a+");

    printf("Bem-Vindo ao Resta 1!\n\nDigite:\n1 - Novo Jogo\n2 - Carregar Jogo\n3 - Sair\n");
    scanf("%d",&escolha);
    if(escolha ==2){
        CarregaJogo(arquivo, matriz, selecionado);
        printf("implementar carregamento\n");
    }else if(escolha==3){
        exit(1);
    }
    while(1){

        printaMatriz(matriz, selecionado, trocaEstado);
        if(trocaEstado){
            printf("Você está no modo de movimentar pecas.\n");
            printf("por favor, digite o movimento: ");
            fgets(movimentos, 13, stdin);
            moveSelecionadoMultiplo(matriz, selecionado, movimentos, 13);
                    
        }
        else{
            printf("Você está no modo de comer pecas.\n");
            printf("por favor, digite o movimento: ");
            direcao = (getchar() - 48);
            while(getchar() != '\n');
        }
        
        if(direcao == 65){
            if(trocaEstado){
                trocaEstado = 0;
            }
            else{
                trocaEstado = 1;
            }
        }
        if(trocaEstado){
            moveSelecionado(selecionado,direcao);
        
        }
        else{
            canMove = podeMover(matriz,selecionado,direcao);
            if(!canMove){
                movePeca(matriz, (selecionado), direcao);
            }
        }

        #ifdef __linux__ 
            printf("\033[1;1H\033[2J");
        #elif _WIN32
            system(cls)

        #endif
        estadoDoJogo =verificaVitoria(matriz); 
        if(estadoDoJogo){
            printf("Você ganhou!!!\n");
            break; 
        };
        estadoDoJogo = verificaDerrota(matriz);
        if(!estadoDoJogo){
            printf("Você perdeu :C\n");
            break;
        };
    }
    
    return 0;
}