#include <stdio.h>
/*
	Programa: Exercício Nº6
	Autor: Igor de Andrade Assunção de Almeida
	DRE: 121095736
	Data: 21/07/2021
*/
int main(void){
    int number, sum;
    printf("Por favor, digite um numero Inteiro (ex: 10): ");
    scanf("%d", &number);
    sum = ((number+1)*number )/2 ;
    printf("%d\n", sum);
    return 0;
}
