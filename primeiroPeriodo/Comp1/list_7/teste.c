#include <stdio.h>


int main(int argc, char const *argv[])
{
    int nb10=10, resto, nb2[32]={0},i=0,aux;
    while (nb10!=0){
        resto = nb10%2;
        nb10 = nb10/2;
        nb2[i] = resto;
        i++;
    }
    for(i=i; i<32; i++) nb2[i] = 0;
    for(i=0;i<(32/2); i++){
        aux = nb2[i];
        nb2[i] = nb2[32 -i-1];
        nb2[32 -i-1] = aux;
    }
    
    for(i=0; i<32; i++){
        printf("%d", nb2[i]);
    } 
    printf("\n");

    return 0;
}


