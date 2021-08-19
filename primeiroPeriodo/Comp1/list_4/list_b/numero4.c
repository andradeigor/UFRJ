#include <stdio.h>

int main(){
    int identificador,
    confereIdentificador=0
    ,confereValorProduto=0;
    float valorProduto, valorReal;

    printf("O programa calcula descontos na compra de produtos com base em seu status.\n");
    printf("Identificador para clientes: numero 1\nPara funcionarios: numero 2\nE vips: numero 3\n");
    printf("Apos se identificar, digite o valor do produto\n");
    while(confereIdentificador==0){
        printf("Por favor, digite o seu status (ex: 1): ");
        scanf("%d", &identificador);
        while((getchar())!='\n');
        if(identificador>3 || identificador <=0 ) continue;
        confereIdentificador = 1;
    }
        while(confereValorProduto==0){
        printf("Por favor, digite o valor do produto. Valor quebraso de separa por . (ex: 100.60): ");
        scanf("%f", &valorProduto);
        while((getchar())!='\n');
        if(valorProduto <= 0 ) continue;
        confereValorProduto = 1;
    }
    switch (identificador)
    {
    case 1:
        valorReal = valorProduto;
        break;
    case 2:
        valorReal = valorProduto *0.9;
        break;
    case 3:
        valorReal = valorProduto *0.95;
        break;
    }
    
    printf("===================== \n");
    printf("O valor a ser pago e: %1.1f \n", valorReal);
    printf("===================== \n");
    return 0;
}