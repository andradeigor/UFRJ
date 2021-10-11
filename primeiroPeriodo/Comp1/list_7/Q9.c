#include <stdlib.h>
#include <stdio.h>

int main(void){
    int i, n, *pvetor,mMedia=0 ;
    float media;
    /* Define um valor para n , scanf ou n = */
    scanf ("%d", &n);
    
    /* aloca espaco na memoria */
    pvetor = (int *) malloc (n*sizeof( int ));
    
    if(!pvetor) {
        puts("Sem memoria.");
        return 1;
    }
    /* aqui uso pvetor , vamos ler um vetor */
    for (i = 0;i < n;i ++) {
        scanf ("%d", pvetor+i);
    }
    /* faco alguma coisa */
    
    media = 0.0;
    for (i = 0;i < n;i ++) media += *(pvetor+i);
    
    media/=n;
    
    for (i = 0;i< n;i ++){
        /* verifica se algum dos elementos de pvetor é maior que a média, se for, soma um a variável mMedia*/
        if (*(pvetor+i)> media) mMedia++;
    }
    printf ("a media e: %1.2f\n", media);
    printf ("O numero de valores maiores que a media e: %d\n", mMedia);
    /* aqui nao preciso mais de pvetor */
    free (pvetor);
    return 0;
    }