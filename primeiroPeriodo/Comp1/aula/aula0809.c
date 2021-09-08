#include <stdio.h>
#include <stdlib.h>

int ParOuImpar(int numero){
    if(numero%2 ==0) return 1;
    return 0;
}
int main(int argc, char *argv[]){
    int i, par;
    if(argc<2){
        printf("Por favor, digite os argumentos adicionais!\n");
    }
    for(i=1;i<argc;i++){
        par = ParOuImpar(atoi(argv[i]));
        if(par){
            printf("O numero %s é par\n", argv[i]);
        }else{
            printf("O numero %s é impar\n", argv[i]);
        }
    }
    return 0;
}