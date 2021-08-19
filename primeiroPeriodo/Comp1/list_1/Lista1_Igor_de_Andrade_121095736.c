#include <stdio.h>
/*
	Programa: Exercício Nº5
	Autor: Igor de Andrade Assunção de Almeida
	DRE: 121095736
	Data: 21/07/2021
	Descrição: O programa calcula a média das duas provas 
			   e retorna se a pessoa foi aprovada ou não
*/
int main(){
	float notaP1,notaP2,media;
	int confereP1=0, confereP2=0;
	while(confereP1==0){
		printf("Por favor, digite a sua nota na P1(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaP1);
		if(notaP1 >=0 && notaP1 <=10 ){
			confereP1 = 1;
		}
	}
	while(confereP2==0){
		printf("Por favor, digite a sua nota na P2(notas são entre 0 e 10, notas quebradas se separam por . ex: 5.5): ");
		scanf("%f", &notaP2);
		if(notaP2 >=0 && notaP2 <=10){
			confereP2=1;
		}
	}
	media = (notaP1+notaP2)/2;
	if(media >=5.0){
		printf("Parabéns, você foi aprovado com a média de %1.1f \n", media);
	}
	else{
		printf("Que pena, você foi reprovado com a média de %1.1f \n", media);
		
	}
	return 0;
}
