#include <stdio.h>
/*
	Programa: Exercício Nº5
	Autor: Igor de Andrade Assunção de Almeida
	DRE: 121095736
	Data: 21/07/2021
*/
int main(void){
    float notaT1,notaT2,notaT3,prova, media;
    int confereT1=0, confereT2=0, confereT3=0, confereProva=0;
    while(confereProva==0){
		printf("Por favor, digite a sua nota na Prova(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &prova);
		while((getchar())!='\n');
		if(prova >=0 && prova <=10){
			confereProva=1;
		}
	}

    while(confereT1==0){
		printf("Por favor, digite a sua nota no Teste 1(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaT1);
		while((getchar())!='\n');
		if(notaT1 >=0 && notaT1 <=10 ){
			confereT1 = 1;
		}
	}
	while(confereT2==0){
		printf("Por favor, digite a sua nota no Teste 2(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaT2);
		while((getchar())!='\n');
		if(notaT2 >=0 && notaT2 <=10){
			confereT2=1;
		}
	}
    while(confereT3==0){
		printf("Por favor, digite a sua nota no Teste 3(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaT3);
		while((getchar())!='\n');
		if(notaT3 >=0 && notaT3 <=10){
			confereT3=1;
		}
	}

    media = (0.8 * prova) + (0.2 * ((notaT1+notaT2+notaT3)/3));
    printf("===================== \n");
    printf("Prova: %1.1f \n", prova);
    printf("Teste 1: %1.1f \n", notaT1);
    printf("Teste 2: %1.1f \n", notaT2);
    printf("Teste 3: %1.1f \n", notaT3);
    printf("Nota Final: %1.1f \n", media);
    printf("===================== \n");
}
