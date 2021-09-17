#include <stdio.h>
#include <stdlib.h>

int comparar (int i, int j);

int main (int argc, char *argv[]){
    int numero1, numero2, comparado;
    if(argc  >= 3){
    numero1 = atoi(argv[1]); /* validar o retorno da atoi */
    numero2 = atoi(argv[2]); /* validar o retorno da atoi */
	comparado = comparar (numero1, numero2);
	printf("O menor numero eh: %d\n", comparado);
}
else{
    printf("Erro! Uso: ./teste numero1 numero2\n");
    return 1;
}
    return 0;
}

int comparar (int i, int j){
	int menor;
    menor = (i > j) ?   j : i;
    return menor;
}
