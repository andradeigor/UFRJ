#include <stdio.h>
#include <string.h>
#define DIM 21

int main(void){
    char string1[DIM],
    string2[DIM],
    string3[DIM*2],
    aux,
    caractere;

    int i,
    opcao, 
    posicao,
    size;

    printf("Por favor, digite uma string de até 20 caracteres: ");
    fgets(string1, DIM, stdin);
    for(i=0; i<DIM; i++){
        if(string1[i] == '\n') string1[i] = '\0';
    }
    printf("Por favor, digite uma segunda string de até 20 caracteres: ");
    fgets(string2, DIM, stdin);
    for(i=0; i<DIM; i++){
        if(string2[i] == '\n') string2[i] = '\0';
    }
    printf("Por favor, digite a opção desejada:\n");
    printf("1. Mostre as strings invertidas;\n");
    printf("2. Copie (ou concatene) as duas strings em outro vetor, imprimindo a resposta;\n");
    printf("3. Compare as duas strings e informe quem é a string maior;\n");
    printf("4. Informe a string de maior tamanho;\n");
    printf("5. Identifique a ocorrência de determinado caractere na string e informa sua posicao;\n");
    scanf("%d", &opcao);
    while((getchar())!='\n');
    switch (opcao)
    {
    case 1:
        for(i=0;i<(strlen(string1)/2); i++){
            aux = string1[i];
            string1[i] = string1[strlen(string1) -i-1];
            string1[strlen(string1) -i-1] = aux;
        }
        for(i=0;i<(strlen(string2)/2); i++){
            aux = string2[i];
            string2[i] = string2[strlen(string2) -i-1];
            string2[strlen(string2) -i-1] = aux;
        }
        printf("A primeira string invertida fica: %s\n", string1);
        printf("A primeira string invertida fica: %s\n", string2);
        break;
    case 2:
        strcpy(string3, string1);
        strcat(string3, string2);
        printf("As string concatenadas gerou: %s\n", string3);
    case 3:
        if(strlen(string1)>strlen(string2)){
            printf("Primeira string\n");
        }
        else if(strlen(string1) < strlen(string2)){
            printf("Segunda string\n");
        }else{
            printf("Mesmo tamanho\n");
        }
    case 4:
        if(strlen(string1)>strlen(string2)){
            printf("%s\n", string1);
        }
        else if(strlen(string1) < strlen(string2)){
            printf("%s\n", string2);
        }else{
            printf("Mesmo tamanho\n");
        }
    case 5:

        printf("Por favor, digite o caractere que deseja procurar: ");
        caractere = getchar();
        while((getchar())!='\n');
        printf("%c\n", caractere);
        for(i=0;i<strlen(string1);i++){
            if(string1[i] ==caractere){
                posicao = i;
                printf("o caractere procurado está na posicao %d da primeira string\n", posicao);
                break;
            } 
        }
        for(i=0;i<strlen(string2);i++){
            if(string2[i] ==caractere){
                posicao = i;
                printf("o caractere procurado está na posicao %d da segunda string\n", posicao);
                return 0;
            } 
        }
        printf("O caractere informado nao esta presente nas strings\n");
    default:
        break;
    }

    return 0;
}