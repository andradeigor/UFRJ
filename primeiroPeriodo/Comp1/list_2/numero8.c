/*
* Programa : mediaNotas .c
* Autor : Adriano Cruz
* Descricao : Calcula media de aluno e informa se ele foi aprovado ou n~ao .
* Data : 2013/08/27
*/

#include <stdio.h>
int main (void) {
    float notaAluno = -1;
    float mediaAluno =0;
    float confereNumProvas = 0;
    int notasLidas = 0;
    int quantProvas;

    while((confereNumProvas==0)){
        printf("Por favor, digite a quantidade de provas (ex: 3): ");
        scanf("%d", &quantProvas);
        while((getchar())!='\n'){};
        if(quantProvas >0 && quantProvas < 100){
            /* Aqui, pelo bem da minha sanidade mental estal considerando que ninguém faz mais
            de 100 provas*/
            confereNumProvas = 1;
        }
    }
    while(notasLidas < quantProvas){
        printf("Por favor, digite sua nota na prova %d(ex: 5.5): " , (notasLidas +1));
        scanf("%f", &notaAluno);
        while((getchar())!='\n'){};
        if(notaAluno >=0 && notaAluno <=10){
            notasLidas += 1;
            mediaAluno += notaAluno;
        }
    }
    mediaAluno = mediaAluno/ quantProvas;
    printf("A media do aluno foi %1.1f\n", mediaAluno);
    if(mediaAluno >= 5.0){
        printf("Parabéns, você foi aprovado \n");
    }else{
        printf("Que pena, você foi reprovado \n");
    }
    return 0;
}