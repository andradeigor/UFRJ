/*
* Programa : mediaNotas .c
* Autor : Adriano Cruz
* Descricao : Calcula media de aluno e informa se ele foi aprovado ou n~ao .
* Data : 2013/08/27
*/
#include <stdio.h>
int main (void) {
    float notaAluno ;
    float mediaAluno = 0;
    int confereNota =0;
    while(confereNota==0){
		printf("Por favor, digite a sua nota na Prova 1(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaAluno);
        while((getchar())!='\n'){};
		if(notaAluno >=0 && notaAluno <=10){
			confereNota=1;
		}
	}
    mediaAluno += notaAluno;
    confereNota = 0;
        while(confereNota==0){
		printf("Por favor, digite a sua nota na Prova 2(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaAluno);
        while((getchar())!='\n'){};
		if(notaAluno >=0 && notaAluno <=10){
			confereNota=1;
		}
	}
    mediaAluno += notaAluno;
    confereNota = 0;
        while(confereNota==0){
		printf("Por favor, digite a sua nota na Prova 3(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaAluno);
        while((getchar())!='\n'){};
		if(notaAluno >=0 && notaAluno <=10){
			confereNota=1;
		}
	}
    mediaAluno = (mediaAluno + notaAluno)/3;
    printf("A media do aluno foi %1.1f\n", mediaAluno);
    if(mediaAluno >= 5.0){
        printf("Parabéns, você foi aprovado \n");
    }else{
        printf("Que pena, você foi reprovado \n");
    }
    return 0;
}