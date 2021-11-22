#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define DIM 7

typedef struct _PONTOS{
    char estadoAtual;
    int x,y;
} PONTOS;



int podeMover(PONTOS matriz[][DIM], int *selecionado, int direcao){
    /*  Essa funcao cerifica se e possivel movimentar(eliminar) uma peca dada uma certa direcao. 
        Caso o movimento seja possível, a funcao retorna 0. Caso a peca nao possa ser movida ou 
        a direcao digita nao seja valida, a funcao retorna 0*/
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    if(((ponteiro+(*(selecionado+1))*DIM)+(*selecionado))->estadoAtual != 'o') {
        return 1;
    }
    switch(direcao){
        case 2:
            if(((ponteiro+(*(selecionado+1)+1)*DIM)+(*selecionado))->estadoAtual == 'o' && ((ponteiro+(*(selecionado+1)+2)*DIM)+*selecionado)->estadoAtual == '.' ){
                /*Em todos os cases, é feita uma checagem se a peça está no do tabuleiro. Caso a direção do movimento feito pelo jogador 
                ultrapasse os limites do tabuleiro, a função impede que o movimento seja feito. Sem esse if, existe a possibilidade da 
                função autorizar uma elminção de uma peça que está em uma linha posterior da matriz. */
                if(*(selecionado+1)+1 > 6 || (*(selecionado+1)+2) > 6 || (*(selecionado+1)+2) < 0 ||(*(selecionado+1)+1) < 0) break;
                return 0;
            }
            break;
        case 4:
            if(((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)-1))->estadoAtual == 'o' && ((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)-2))->estadoAtual == '.' ){
                if(*(selecionado)-1 > 6 || (*(selecionado)-2) > 6 ||*(selecionado)-1 < 0 || (*(selecionado)-2) < 0) break;
                return 0;
            }
            break;
        case 6:
            if(((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)+1))->estadoAtual == 'o' && ((ponteiro+*(selecionado+1)*DIM)+(*(selecionado)+2))->estadoAtual == '.' ){
                if( *(selecionado)+1 < 0 || (*(selecionado)+2) < 0||*(selecionado)+1 > 6 || (*(selecionado)+2) > 6) break;
                return 0;
            }
            break;
        case 8:
            if(((ponteiro+(*(selecionado+1)-1)*DIM)+*(selecionado))->estadoAtual == 'o' && ((ponteiro+(*(selecionado+1)-2)*DIM)+*(selecionado))->estadoAtual == '.' ){
                if(*(selecionado+1)-1 >6 || (*(selecionado+1)-2) >6||*(selecionado+1)-1 < 0 || (*(selecionado+1)-2) < 0) break;
                return 0;
            }
            break;
        default: 
            break;
    }
    return 1;
}
int podeMoverTudo(PONTOS matriz[][DIM], int x, int y){
    /* Essa funcao serve de suporte para a funcao "verificaDerrota" 
    ela verifica se a peca pode ser movida em alguma das 4 possiveis direcões.
    Caso nao possa, a funcao retorna 1, que indica que a peca nao pode se locomover*/
    int moves[4] = {2,4,6,8}, i, movimento;
    int *ponto;
    ponto = (int*) malloc(sizeof(int)*2);
    *(ponto) = x;
    *(ponto+1) = y;
    for(i=0; i<4; i++){
        movimento = podeMover(matriz, ponto, moves[i]);
        if(!movimento) {
            return 1;
            };  
    }
    free(ponto);
    return 0;
}



void moveSelecionadoMultiplo(PONTOS matriz[][7], int *selecionado, char *movimentos, int tamanho){
    int i;
    char* ponteiro = movimentos;
    PONTOS *endereco = &matriz[0][0];
    for(i=0; i<tamanho; i++){
        /*  Esse e um loop que percorre o vetor de caracteres com as direcões que irao mover o cursor selecionado. 
            O cursor e movido ate que o \0 seja encontrado na entrada inserida pelo usuario.*/
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

    /*Insere os espacos nos elementos da matriz*/
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = ' ';
            ((ponteiro+i*DIM)+ j)->x = j;
            ((ponteiro+i*DIM)+ j)->y = i;
        }
    }

    /*Desenha a parte horizontal da cruz, com as pecas sendo sinalizadas pelo 'o'*/
    for(i=2; i<5; i++){
        for(j=0; j<DIM; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = 'o';
        }
    }

    /*Desenha a parte vertical da cruz, com as pecas sendo sinalizadas pelo 'o'*/
    for(i=0; i<DIM; i++){
        for(j=2; j<5; j++){
            ((ponteiro+i*DIM)+ j)->estadoAtual = 'o';
        }
    }

    /*Transforma o elemento central da cruz em um '.', que indica um espaco sem pecas.*/
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
            /*Verifica se a coordenada atual do loop e a selecionada. se for, 
            printa ela ou com () ou com [] para indicar qual campo esta selecionado.*/
            if(j == selecionado[0] && i == selecionado[1]){
                trocaEstado? printf("[%c]", ((ponteiro+i*DIM)+ j)->estadoAtual):printf("(%c)", ((ponteiro+i*DIM)+ j)->estadoAtual);
            }else{
                printf(" %c ", ((ponteiro+i*DIM)+ j)->estadoAtual);
            }
        }
        printf("\n");
    }
}


void movePeca(PONTOS matriz[][DIM],int* selecionado, int direcao){
    PONTOS* ponteiro;
    ponteiro = &matriz[0][0];
    switch (direcao){
    /*  O switch executa o movimento da peca baseado na direcao inserida pelo jogador,
        Se a funcao foi requisitada, a entrada ja foi verificada como um movimento valido e sera executada.
        O movimento e feito transformando a peca que foi usada para comer de (o) para '.'
        e transformando a peca seguinte a ela tambem e transformada em '.' 
        Alem disso, o local de detino tambem e transformado para o símbolo 'o'. 
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
    /* O for percorre as pecas do tabuleiro e conta o número de pecas presentes. 
       Se só houver uma peca, a funcao retorna 1, sinalizando que o jogo acabou e o jogador ganhou
       Caso contario, a funcao retorna 0.*/
    if(bolinha == 1) return 1;
    return 0;
}

int verificaDerrota(PONTOS matriz[][DIM]){
    int x, y, pode;
    PONTOS *ponteiro;
    ponteiro = &matriz[0][0];
    for(y = 0; y < DIM; y++){
        for(x = 0; x < DIM; x++){
            /* O for percorre todas as pecas do tabuleiro e verifica se ela pode mover. 
               Se alguma peca pode mover ela, a funcao retorna 1 para indicar que o jogo ainda nao acabou.
               Caso nenhuma peca possa se mover, a funcao retorna 0, indicando que o jogo acabou*/
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
    /*A funcao verifica se existe algum conteúo no arquivo, caso contrario printa que nao ha jogos salvos e retorna 1*/
    if(letra ==EOF){
        printf("Nao ha jogos salvos, favor comecar um novo!\n");
        return 1;   
    }
    /*Executa o loop enquanto nao for o detectado o fim do arquivo*/
    while(letra !=EOF){
        /*O numero 5 indica que o jogador esta no modo de movimentar pecas, 
        ou seja, todos os numeros a partir da ocorrencia do numero 5 ate o '\n' 
        serao usados para mover o cursor. Ex:q688 executara o mmovimento 688 */
        if(letra =='5'){
            i=0;
            while(letra!='\n'){
                letra = fgetc(movimento);
                movimentos[i] = letra;
                i++;

            }
            movimentos[i] = '\0';
            moveSelecionadoMultiplo(matriz,selecionado,movimentos,13);
        }else{
            /*Caso o numero nao tenha um 5 anterior a ele, o movimento sera de comer peca*/
            movimentoValido = podeMover(matriz,selecionado,letra - 48);
            if(!movimentoValido){
                movePeca(matriz, (selecionado), letra - 48);
            }
        }
        /*avanca o ponteiro de caracteres no arquivo, 
        para continuar a execucao no próximo loop*/
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

    /*abre o arquivo movimento.txt, caso ele nao existe, o paremetro a+ garante que ele sera criado*/
    arquivo = fopen("movimento.txt", "a+");
    /*limpa a tela para que novas informacões sejam printadas,
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
        /* menu de opcoes, caso digite algo fora 
        das opcoes ira solicitar novamente para digitar o input*/
        printf("Digite:\n  1 - Novo Jogo\n  2 - Carregar Jogo\n  3 - Regras do jogo\n  4 - Como jogar\n  5 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&escolha);

        if(escolha <= 0 || escolha >= 6) printf("Comando invalido! Favor digitar um dos valores solicitados!");

        if(escolha == 1){
            /* se escolher um novo jogo ira zerar o txt */
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
            printf("   +-------------------------------------------------------------------------------------------------+\n");
            printf("   | 1 - O jogo se inicia com 32 pecas e um espaco vazio no centro. O jogador devera, atraves de     |\n");
            printf("   |    movimentos validos, comer todas as pecas ate que reste apenas uma no tabuleiro.              |\n");
            printf("   | 2 - Um movimento e valido apenas se:                                                            |\n");
            printf("   |    . A casa selecioanda para ser movida e uma peca;                                             |\n");
            printf("   |    . A casa imediatamente ao lado da selecionada, na direcao do movimento, tambem e uma peca;   |\n");
            printf("   |    . Ha um espaco vazio na casa que se pretende mover a peca seleionada.                        |\n"); 
            printf("   | 3 - Divirta-se!                                                                                 |\n");
            printf("   +-------------------------------------------------------------------------------------------------+\n");
        }



        else if(escolha == 4){
            #ifdef __linux__ 
                printf("\033[1;1H\033[2J");
            #elif _WIN32
                system("cls");
            #endif
            printf("   +--------------------------------------------------------------------------------------------------+\n");
            printf("   | 1 - Sempre havera uma posicao selecionada, e e a partir dela que o jogador deve se orientar.     |\n");
            printf("   |                                                                                                  |\n");
            printf("   | 2 - Se a posicao selecionada estiver marcada com parenteses, o jogo esta no modo de comer pecas, |\n");
            printf("   |     bastando escolher a direcao da eliminacao. Se for valido, o comando sera executado.          |\n");
            printf("   |                                                                                                  |\n");
            printf("   | 3 - Se a posicao selecionada estiver marcada com colchetes, o jogo esta em modo de movimentacao. |\n");
            printf("   |     Nesse modo, basta digitar todos os movimentos a serem realizados e apertar a tecla enter.    |\n");
            printf("   |                                                                                                  |\n");
            printf("   |     Exemplo: Esquerda Esquerda Cima Cima Enter.                                                  |\n"); 
            printf("   |     Nesse caso, a posicao selecionada se deslocara 2 para a esquerda e 2 para cima               |\n");
            printf("   |                                                                                                  |\n");
            printf("   | 4 - A tecla que altera entre o modo comer e o modo movimentar selecionado e numero 5             |\n");
            printf("   |     O jogo deve ser jogado utilizando as setas do teclado numerico(Num Pad).                     |\n");
            printf("   |                                                                                                  |\n"); 
            printf("   |     Assim, 4 corresponde a esquerda, 6 a direita, 2 para baixo e 8 para cima                     |\n");
            printf("   |                                                                                                  |\n");
            printf("   |     Teclas utilizadas para jogar:                                                                |\n");
            printf("   |     2 - Mover para baixo                                                                         |\n");
            printf("   |     4 - Mover para a esquerda                                                                    |\n");
            printf("   |     6 - Mover para a direita                                                                     |\n");
            printf("   |     8 - Mover para a cima                                                                        |\n");
            printf("   +--------------------------------------------------------------------------------------------------+\n");
        }   


        if(escolha==5){
            exit(1);
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
            /* se o troca estado for 1, esta no modo de mover peca entao ira chamar a funcao que move o selecionado*/
            printf("\nVoce esta no modo de movimentar pecas.\n");
            printf("Por favor, digite o movimento: ");
            fgets(movimentos, 13, stdin);
            moveSelecionadoMultiplo(matriz, selecionado, movimentos, 13);
            /*escreve no txt o que foi digitado*/
            fprintf(arquivo,"5%s", movimentos);
            fflush(arquivo);
                    
        }
        else{
            /*se o troca estado for 0, esta no modo comer pecas e ira salvar o valor digitado em direcao*/
            printf("\nVoce esta no modo de comer pecas.\n");
            printf("Por favor, digite o movimento: ");
            direcao = (getchar() - 48);
            while(getchar() != '\n');
        }
        
        if(direcao == 5){
            /* Se direcao for igual a 5, que em ascii tem o código 53, subtraímos 48, com resultado 5.
               Caso o valor digitado seja 5, deve trocar o estado para entrar no modo de mover peca */
            if(trocaEstado){
                trocaEstado = 0;
            }
            else{
                trocaEstado = 1;
            }
        }
        /*aqui faz o movimento caso trocaestado seja 0*/
        if(!trocaEstado){
            canMove = podeMover(matriz,selecionado,direcao);
            if(!canMove){
                movePeca(matriz, (selecionado), direcao);
                /*salva o valor no arquivo*/
                fprintf(arquivo, "%d", direcao);
                fflush(arquivo);
            }
        }


        estadoDoJogo =verificaVitoria(matriz); 
        if(estadoDoJogo){
            /*verifica se o jogador ganhou*/
            printf(" __      __        //\\    _____             _                   _   _ \n \\ \\    / /       |/ \\|  / ____|           | |                 | | | |\n  \\ \\  / /__   ___ ___  | |  __  __ _ _ __ | |__   ___  _   _  | | | |\n   \\ \\/ / _ \\ / __/ _ \\ | | |_ |/ _` | '_ \\| '_ \\ / _ \\| | | | | | | |\n    \\  / (_) | (_|  __/ | |__| | (_| | | | | | | | (_) | |_| | |_| |_|\n     \\/ \\___/ \\___\\___|  \\_____|\\__,_|_| |_|_| |_|\\___/ \\__,_| (_) (_)\n\n                                                                      ");
            break; 
        };
        estadoDoJogo = verificaDerrota(matriz);
        if(!estadoDoJogo){
            /* verifica se o jogador perdeu*/
            printf(" __      __        //\\   _____             _                    \n \\ \\    / /       |/ \\| |  __ \\           | |             _     \n  \\ \\  / /__   ___ ___  | |__) |__ _ __ __| | ___ _   _  (_)___ \n   \\ \\/ / _ \\ / __/ _ \\ |  ___/ _ \\ '__/ _` |/ _ \\ | | |   / __|\n    \\  / (_) | (_|  __/ | |  |  __/ | | (_| |  __/ |_| |  | (__ \n     \\/ \\___/ \\___\\___| |_|   \\___|_|  \\__,_|\\___|\\__,_| (_)___|\n\n                                                                ");
            break;
        };
    }
    
    return 0;
}