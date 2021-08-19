#include <stdio.h>

int main(){
    int mes,
    confereMes=0;

    printf("O programa converte o numero do mes para o seu nome.\n");
    printf("numeros validos vao de 1 a 12\n");
    while(confereMes==0){
        printf("Por favor, digite o seu status (ex: 1): ");
        scanf("%d", &mes);
        while((getchar())!='\n');
        if(mes<1 || mes >12 ) continue;
        confereMes = 1;
    }
    switch (mes)
    {
    case 1:
        printf("O mes é janeiro\n");
        break;
    case 2:
        printf("O mes é fevereiro\n");
        break;
    case 3:
        printf("O mes é março\n");
        break;
    case 4:
        printf("O mes é abril\n");
        break;
    case 5:
        printf("O mes é maio\n");
        break;
    case 6:
        printf("O mes é junho\n");
        break;
    case 7:
        printf("O mes é julho\n");
        break;
    case 8:
        printf("O mes é agosto\n");
        break;
    case 9:
        printf("O mes é setembro\n");
        break;
    case 10:
        printf("O mes é outubro\n");
        break;
    case 11:
        printf("O mes é novembro\n");
        break;
    case 12:
        printf("O mes é dezembro\n");
        break;
    }
    
    return 0;
}