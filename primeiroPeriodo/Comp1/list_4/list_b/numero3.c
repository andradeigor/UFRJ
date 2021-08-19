#include <stdio.h>

int main(){
    int notas=0,
    numNotas=3;
    float
    notaAtual,
    notasAcumuladas=0,
    notasMedia;
    printf("O programa calcula a média de 3 notas e retorna a média entre elas.\n");
    printf("Valores negativos indicam o fim da leitura e as notas restantes são consideradas como 0\n");
    printf("Caso o usuário digite uma quarta nota o programa irá calcular a media com base nas 3 primeiras\n");
    while(1){
        printf("Por favor, digite sua nota. Nota com valor negativo indica o fim da leitura (ex:8): ");
        scanf("%f", &notaAtual);
        while((getchar())!='\n');
        if(notaAtual>10){
            continue;
        }
        if(notaAtual < 0) break;
        notas +=1;
        notasAcumuladas += notaAtual;
        notasMedia = notasAcumuladas/numNotas;
        if(notas %3 ==0){
            printf("===================== \n");
            printf("O numero de notas lidas/consideradas foi: %d \n", numNotas);
            printf("A media de notas e: %1.1f \n", notasMedia);
            printf("===================== \n");
            notasAcumuladas = 0;
        }

    }
    return 0;
}