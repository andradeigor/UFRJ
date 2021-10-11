#include <stdio.h>
#include <stdlib.h>

char *areaAlocada (int tam){
	char *pArea;
    pArea = (char *) calloc ((tam + 1), sizeof(char));
	if (!pArea){
		printf("Erro na alocação!\n");
		exit(1);
	}
	return pArea;
}

int main (void){
	int tam;
	char *p;
	printf("Qual o tamanho desejado?\n");
	scanf("%d", &tam);
	p = areaAlocada(tam);
	*p = 'a';
	printf("%s\n", p);
	free(p);
	return 0;

}
