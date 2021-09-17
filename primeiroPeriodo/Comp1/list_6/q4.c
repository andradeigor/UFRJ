#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    int resto;
    resto = a%b;
    return resto == 0? b: gcd(b,resto);
}

int main(int argc, char *argv[]){
    int a,b;
    if(argc <3){
        printf("digite dois argumentos junto a chamada da função\n");
        return 1;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("O mmc entre %d e %d é %d\n", a,b,((a*b)/gcd(a,b)));
    return 0;
}

