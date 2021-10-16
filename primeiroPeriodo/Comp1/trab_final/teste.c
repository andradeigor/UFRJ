#include <stdio.h>

int main() {
    FILE *movimento;
    int letra,movimentoValido,i;
    char movimentos[13];
    movimento = fopen("movimentos.txt", "a+");
    letra = fgetc(movimento);
    if(letra ==EOF){
        printf("Não há jogos salvos, favor começar um novo!\n");
        return 1;   
    }
    while(letra !=EOF){
        printf("letra normal %d\n", letra-48);
        if(letra =='q'){
            i=0;
            while(letra!='\n'){
                letra = fgetc(movimento);
                printf("letra q%d\n", letra-48);
                movimentos[i] = letra;
                i++;

            }
            movimentos[i+1] = '\0';
        }
        letra = fgetc(movimento);
    }
    return 0;

}