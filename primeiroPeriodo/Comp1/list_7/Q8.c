#include <stdio.h>
#include <stdlib.h>

int main(){

    int n=0,*pvetor, max;
    while (1){
        pvetor = (int*) malloc (1024*1024*n*sizeof(char));/* 1048576*/
        max = n;
        if(!pvetor) break;
        n++;
        free(pvetor);       
    }
    printf("Cheguei no meu limite.O numero maximo de megabytes foi %d\n", max);

    return 0;
}

