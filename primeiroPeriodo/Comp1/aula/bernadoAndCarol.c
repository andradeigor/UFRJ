#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    int quantidadeDeMegabytes;
    int *ponteiroDeControle;
    long double quantidadeDeBytes = 0;

    for(quantidadeDeMegabytes = 1; ; quantidadeDeMegabytes++)
    /* neste for definimos a quantidade inicial de megabytes alocados como 1, aumentando de um em um, até que o ponteiro de controle que recebe
     a área de memória ultrapasse a memória máxima possível */
    {
        ponteiroDeControle = ( int *) malloc (quantidadeDeMegabytes * 1024 * 1024);
        /* dentro da função malloc calculamos o número de megabytes alocados */
        if(!ponteiroDeControle){
            break;
        }
        else{
            free(ponteiroDeControle);
        }
    }

    quantidadeDeBytes = (double) quantidadeDeMegabytes * 1024 * 1024;

    printf("%Lf\n", quantidadeDeBytes);
    printf("%d\n", quantidadeDeMegabytes);
    /* printf("O maior segmento de memoria que este computador consegue alocar e %d bytes! (%d Megabytes)\n", quantidadeDeBytes, quantidadeDeMegabytes);*/
    return 0;
}