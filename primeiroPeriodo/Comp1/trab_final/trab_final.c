#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define DIM 7

typedef struct _PONTOS{
    char estadoAtual;
    int x,y;
} PONTOS;



int podeMover(PONTOS matriz[][DIM], int *selecionado, int direcao){
    /*  Essa função cerifica se é possivel movimentar(eliminar) uma peça dada uma certa direção. 
        Caso o movimento seja possível, a função retorna 0. Caso a peça não possa ser movida ou 
        a direção digita não seja válida, a função retorna 0*/
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    if(((ponteiro+(*(selecionado+1))*DIM)+(*selecionado))->estadoAtual != 'o') {
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
    /* Essa função serve de suporte para a função "verificaDerrota" 
    ela verifica se a peça pode ser movida em alguma das 4 possiveis direções.
    Caso não possa, a função retorna 1, que indica que a peça não pode se locomover*/
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
    switch (direcao){
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
        /*  Esse é um loop que percorre o vetor de caracteres com as direções que irão mover o cursor selecionado. 
            O cursor é movido até que o \0 seja encontrado na entrada inserida pelo usuário.*/
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

    /*Insere os espaços nos elementos da matriz*/
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = ' ';
            ((ponteiro+i*DIM)+ j)->x = j;
            ((ponteiro+i*DIM)+ j)->y = i;
        }
    }

    /*Desenha a parte horizontal da cruz, com as peças sendo sinalizadas pelo 'o'*/
    for(i=2; i<5; i++){
        for(j=0; j<DIM; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = 'o';
        }
    }

    /*Desenha a parte vertical da cruz, com as peças sendo sinalizadas pelo 'o'*/
    for(i=0; i<DIM; i++){
        for(j=2; j<5; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = 'o';
        }
    }

    /*Transforma o elemento central da cruz em um '.', que indica um espaço sem peças.*/
    ((ponteiro+3*DIM)+ 3)->estadoAtual = '.';
}

void printaMatriz(PONTOS matriz[][DIM], int selecionado[], int trocaEstado){
    int i, j;
    /*Percorre a matriz e printa elemento por elemento.*/
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    for(i=0; i<DIM; i++){
        printf("     ");
        for(j=0; j<DIM; j++){
            /*Verifica se a coordenada atual do loop é a selecionada. se for, 
            printa ela ou com () ou com [] para indicar qual campo está selecionado.*/
            if(j == selecionado[0] && i == selecionado[1]){
                trocaEstado? printf("[%c]", ((ponteiro+i*DIM)+ j)->estadoAtual):printf("(%c)", ((ponteiro+i*DIM)+ j)->estadoAtual);
            }else{
                printf(" %c ", ((ponteiro+i*DIM)+ j)->estadoAtual);
            }
        }
        printf("\n");
    }
}

/*(void printaCoordenadas(PONTOS matriz[][DIM]){
    int i,j;
    PONTOS *ponteiros;
    ponteiros = &matriz[0][0];
    for (i = 0; i < DIM; i++){
        for (j = 0; j < DIM; j++){
            printf("[%d,%d]", ((ponteiros + i *DIM)+j)->x,((ponteiros + i *DIM)+j)->y);
        }
    }
}
*/

void movePeca(PONTOS matriz[][DIM],int* selecionado, int direcao){
    PONTOS* ponteiro;
    ponteiro = &matriz[0][0];
    switch (direcao){
    /*  O switch executa o movimento da peça baseado na direção inserida pelo jogador,
        Se a função foi requisitada, a entrada já foi verificada como um movimento válido e será executada.
        O movimento é feito transformando a peça que foi usada para comer de (o) para '.'
        e transformando a peça seguinte a ela também é transformada em '.' 
        Além disso, o local de detino também é transformado para o símbolo 'o'. 
        Ex: (o) o . -> . . (o)*/
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




int verificaVitoria(PONTOS matriz[][DIM]){
    int x, y, bolinha = 0;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    for(y = 0; y < DIM; y++){
        for(x = 0; x < DIM; x++){
            if(((ponteiro+y*DIM)+x)->estadoAtual == 'o')bolinha++;
        }
    }
    /* O for percorre as peças do tabuleiro e conta o número de peças presentes. 
       Se só houver uma peça, a função retorna 1, sinalizando que o jogo acabou e o jogador ganhou
       Caso contário, a função retorna 0.*/
    if(bolinha == 1) return 1;
    return 0;
}

int verificaDerrota(PONTOS matriz[][DIM]){
    int x, y, pode;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];    
    for(y = 0; y < DIM; y++){
        for(x = 0; x < DIM; x++){
            /* O for percorre todas as peças do tabuleiro e verifica se ela pode mover. 
               Se alguma peça pode mover ela, a função retorna 1 para indicar que o jogo ainda não acabou.
               Caso nenhuma peça possa se mover, a função retorna 0, indicando que o jogo acabou*/
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
    /*A função verifica se existe algum conteúo no arquivo, caso contrário printa que não há jogos salvos e retorna 1*/
    if(letra ==EOF){
        printf("Não há jogos salvos, favor começar um novo!\n");
        return 1;   
    }
    /*Executa o loop enquanto não for o detectado o fim do arquivo*/
    while(letra !=EOF){
        /*A letra 'q' indica que o jogador está no modo de movimentar peças, 
        ou seja, todos os numeros a partir da ocorrência da letra 'q' até o '\n' 
        serão usados para mover o cursor. Ex:q688 executará o mmovimento 688 */
        if(letra =='q'){
            i=0;
            while(letra!='\n'){
                
                letra = fgetc(movimento);
                movimentos[i] = letra;
                i++;

            }
            movimentos[i] = '\0';
            moveSelecionadoMultiplo(matriz,selecionado,movimentos,13);
        }else{
            /*Caso o numero não tenha a letra q anterior a ele, o movimento será de comer peça*/
            movimentoValido = podeMover(matriz,selecionado,letra - 48);
            if(!movimentoValido){
                movePeca(matriz, (selecionado), letra - 48);
            }
        }
        /*avança o ponteiro de caracteres no arquivo, 
        para continuar a execução no próximo loop*/
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
    setlocale(LC_ALL, "Portuguese");

    /* inicia a matriz do jogo*/
    geraMatriz(matriz);

    /*abre o arquivo movimento.txt, caso ele não existe, o parêmetro a+ garante que ele será criado*/
    arquivo = fopen("movimento.txt", "a+");
    /*limpa a tela para que novas informações sejam printadas,
     dependendo do sistema operacional executa um comando diferente.*/
    #ifdef __linux__ 
        /*um hackzinho que funciona da mesma forma que system("clear")
         descobrimos por acaso e decidimos deixar por ser legal*/
        printf("\033[1;1H\033[2J");
    #elif _WIN32
        system("cls");
    #endif
    /*printa uma ascii art do resta 1*/
    printf("  _____           _          __ \n |  __ \\         | |        /_ |\n | |__) |___  ___| |_ __ _   | |\n |  _  // _ \\/ __| __/ _` |  | |\n | | \\ \\  __/\\__ \\ || (_| |  | |\n |_|  \\_\\___||___/\\__\\__,_|  |_|\n                                \n");
    
        printf("Bem-Vindo ao Resta 1!\n\n");
    while(1){
        printf("Digite:\n  1 - Novo Jogo\n  2 - Carregar Jogo\n  3 - Regras do jogo\n  4 - Como jogar\n  5 - Sair\n");
        printf("Opção: ");
        scanf("%d",&escolha);

        if(escolha <= 0 || escolha >= 6) printf("Comando inválido! Favor digitar um dos valores solicitados!");

        if(escolha == 1){
            fclose(fopen("movimento.txt", "w"));
            arquivo = fopen("movimento.txt", "a+");
            break;
        };
        
        if(escolha == 2){
            CarregaJogo(arquivo, matriz, selecionado);
            break;
        }
        else if(escolha == 3){
            #ifdef __linux__ 
                printf("\033[1;1H\033[2J");
            #elif _WIN32
                system("cls");
            #endif
            printf("   ┌─────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
            printf("   │1 - O jogo se inicia com 32 peças e um espaço vazio no centro. O jogador deverá, através de      │\n");
            printf("   │    movimentos válidos, comer todas as peças até que reste apenas uma no tabuleiro.              │\n");
            printf("   │2 - Um movimento é válido apenas se:                                                             │\n");
            printf("   │    . A casa selecioanda para ser movida é uma peça;                                             │\n");
            printf("   │    . A casa imediatamente ao lado da selecionada, na direção do movimento, também é uma peça;   │\n");
            printf("   │    . Há um espaço vazio na casa que se pretende mover a peça seleionada.                        │\n"); 
            printf("   │3 - Divirta-se!                                                                                  │\n");
            printf("   └─────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
        }



        else if(escolha == 4){
            #ifdef __linux__ 
                printf("\033[1;1H\033[2J");
            #elif _WIN32
                system("cls");
            #endif
            printf("   ┌─────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
            printf("   │1 - Sempre haverá uma posição selecionada, e é a partir dela que o jogador deve se orientar.     │\n");
            printf("   │                                                                                                 │\n");
            printf("   │2 - Se a posição selecionada estiver marcada com parênteses, o jogo está no modo de comer peças, │\n");
            printf("   │bastando escolher a direção da eliminação. Se o movimento for válido, o comando será executado   │\n");
            printf("   │                                                                                                 │\n");
            printf("   │3 - Se a posição selecionada estiver marcada com colchetes, o jogo está em modo de movimentação. │\n");
            printf("   │Nesse modo, basta você digitar todos os movimentos a serem realizados e apertar a tecla enter.   │\n");
            printf("   │                                                                                                 │\n");
            printf("   │     Exemplo: Esquerda Esquerda Cima Cima Enter.                                                 │\n"); 
            printf("   │     Nesse caso, a posição selecionada se deslocará 2 para a esquerda e 2 para cima              │\n");
            printf("   │                                                                                                 │\n");
            printf("   │4 - A tecla que altera entre o modo comer e o modo movimentar selecionado é o 'q'                │\n");
            printf("   │    O jogo deve ser jogado utilizando as setas do teclado numérico(Num Pad).                     │\n");
            printf("   │                                                                                                 │\n"); 
            printf("   │    Assim, 4 corresponde à esquerda, 6 à direita, 2 para baixo e 8 para cima                     │\n");
            printf("   │                                                                                                 │\n");
            printf("   │    Teclas utilizadas para jogar:                                                                │\n");
            printf("   │    2 - Mover para baixo                                                                         │\n");
            printf("   │    4 - Mover para a esquerda                                                                    │\n");
            printf("   │    6 - Mover para a direita                                                                     │\n");
            printf("   │    8 - Mover para a cima                                                                        │\n");
            printf("   └─────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
        }   


        if(escolha==5){
            exit(1);
        }
        if(escolha ==1){
            fclose(fopen("movimento.txt", "w"));
            arquivo = fopen("movimento.txt", "a+");
        }
    }
    #ifdef __linux__ 
        printf("\033[1;1H\033[2J");
    #elif _WIN32
        system("cls");

    #endif
    while(getchar() != '\n');
    while(1){
        #ifdef __linux__ 
            printf("\033[1;1H\033[2J");
        #elif _WIN32
            system("cls");
        #endif
        printf("  _____           _          __ \n |  __ \\         | |        /_ |\n | |__) |___  ___| |_ __ _   | |\n |  _  // _ \\/ __| __/ _` |  | |\n | | \\ \\  __/\\__ \\ || (_| |  | |\n |_|  \\_\\___||___/\\__\\__,_|  |_|\n                                \n");
        printaMatriz(matriz, selecionado, trocaEstado);
        if(trocaEstado){
            printf("\nVocê está no modo de movimentar pecas.\n");
            printf("por favor, digite o movimento: ");
            fgets(movimentos, 13, stdin);
            moveSelecionadoMultiplo(matriz, selecionado, movimentos, 13);
            fprintf(arquivo,"q%s", movimentos);
            fflush(arquivo);
                    
        }
        else{
            printf("\nVocê está no modo de comer peças.\n");
            printf("Por favor, digite o movimento: ");
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
                fprintf(arquivo, "%d", direcao);
                fflush(arquivo);
            }
        }


        estadoDoJogo =verificaVitoria(matriz); 
        if(estadoDoJogo){
            printf(" __      __        //\\    _____             _                   _   _ \n \\ \\    / /       |/ \\|  / ____|           | |                 | | | |\n  \\ \\  / /__   ___ ___  | |  __  __ _ _ __ | |__   ___  _   _  | | | |\n   \\ \\/ / _ \\ / __/ _ \\ | | |_ |/ _` | '_ \\| '_ \\ / _ \\| | | | | | | |\n    \\  / (_) | (_|  __/ | |__| | (_| | | | | | | | (_) | |_| | |_| |_|\n     \\/ \\___/ \\___\\___|  \\_____|\\__,_|_| |_|_| |_|\\___/ \\__,_| (_) (_)\n\n                                                                      ");
            break; 
        };
        estadoDoJogo = verificaDerrota(matriz);
        if(!estadoDoJogo){
            printf(" __      __        //\\   _____             _                    \n \\ \\    / /       |/ \\| |  __ \\           | |             _     \n  \\ \\  / /__   ___ ___  | |__) |__ _ __ __| | ___ _   _  (_)___ \n   \\ \\/ / _ \\ / __/ _ \\ |  ___/ _ \\ '__/ _` |/ _ \\ | | |   / __|\n    \\  / (_) | (_|  __/ | |  |  __/ | | (_| |  __/ |_| |  | (__ \n     \\/ \\___/ \\___\\___| |_|   \\___|_|  \\__,_|\\___|\\__,_| (_)___|\n\n                                                                ");
            break;
        };
    }
    
    return 0;
}