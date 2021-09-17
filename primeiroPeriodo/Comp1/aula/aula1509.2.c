#include<stdio.h>
#define TAM 5

int soma(int vetor[]) {
	int i, soma = 0;
	for(i = 0; i < TAM; i++)
		soma += vetor[i];
	return soma;
}

int main(int argc, char *argv[]) {
	int i, vetor[TAM];
	printf("Digite os %d elementos que deseja somar: ", TAM);
	for(i = 0; i < TAM; i++){
		scanf("%d", vetor[i]);
	}
	printf("A soma dos elementos eh: %d", soma(vetor));
	
	return 0;
}
