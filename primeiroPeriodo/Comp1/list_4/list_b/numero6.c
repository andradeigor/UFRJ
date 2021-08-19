#include <stdio.h>

int main(){
    int metodo,
    numero,
    conferemetodo=0;
    printf("Esse programa converte numeros, selecione a opcao desejada\n");
    printf("===================== \n");
    printf(" <Conversão de base >\n");
    printf("1: decimal para hexadecimal\n");
    printf("2: hexadecimal para decimal\n");
    printf("3: decimal para octal\n");
    printf("4: octal para decimal\n");
    printf("5: Encerra\n");
    printf("===================== \n");
    while(conferemetodo==0){
        printf("Por favor, digite o metodo desejado (ex: 1): ");
        scanf("%d", &metodo);
        while((getchar())!='\n');
        if(metodo<1 || metodo >5 ) continue;
        conferemetodo = 1;
    }


    switch (metodo){
    case 1:
        printf("Por favor, digite o Numero desejado (ex: 255): ");
        scanf("%d", &numero);
        while((getchar())!='\n');
        printf("O numero %d em hexadecimal é %X\n",numero,numero);
        break;
    case 2:
        printf("Por favor, digite o Numero desejado (ex: C8): ");
        scanf("%X", &numero);
        while((getchar())!='\n');
        printf("O numero %X em decimal é %d\n",numero,numero);
        break;
    case 3:
        printf("Por favor, digite o Numero desejado (ex: 220): ");
        scanf("%d", &numero);
        while((getchar())!='\n');
        printf("O numero %d em octal é %o\n", numero,numero);
        break;
    case 4:
        printf("Por favor, digite o Numero desejado (ex: 144): ");
        scanf("%o", &numero);
        while((getchar())!='\n');
        printf("O numero %o em decimal é %d\n",numero,numero);
        break;
    case 5:
        printf("Encarrando...\n");
        break;

    }
    return 0;
}