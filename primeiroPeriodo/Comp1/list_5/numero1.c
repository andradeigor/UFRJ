#include <stdio.h>
#define DIM 21

int main(void){
    char string1[DIM],
    string2[DIM],
    string3[DIM*2],
    aux,
    caractere;

    int i,
    opcao, posicao,
    size1=0,size2=0;

    printf("Por favor, digite uma string de até 20 caracteres: ");
    fgets(string1, DIM, stdin);
    for(i=0; i<DIM; i++){
        size1 += 1;
        if(string1[i] == '\n' ||string1[i] == '\0') {
            size1 -= 1; //off by one por causa do \0 ser contado como "tamanho", esse -1 arruma isso
            string1[i] = '\0';
            break;
            }
    }
    printf("Por favor, digite uma segunda string de até 20 caracteres: ");
    fgets(string2, DIM, stdin);
    for(i=0; i<DIM; i++){
        size2 += 1;
        if(string2[i] == '\n' ||string2[i] == '\0') {
            size2 -=1 ;//off by one por causa do \0 ser contado como "tamanho", esse -1 arruma isso
            string2[i] = '\0';
            break;
        }
    }
    printf("Por favor, digite a opção desejada:\n");
    printf("1. Mostre as strings invertidas;\n");
    printf("2. Copie (ou concatene) as duas strings em outro vetor, imprimindo a resposta;\n");
    printf("3. Compare as duas strings e informe quem é a string maior;\n");
    printf("4. Informe a string de maior tamanho;\n");
    printf("5. Identifique a ocorrência de determinado caractere na string e informa sua posicao;\n");
    while(1){
        scanf("%d", &opcao);
        while((getchar())!='\n');
        if(opcao >=1 && opcao<=5){
            break;
        }    
    }
    switch (opcao)
    {
    case 1:
        for(i=0;i<(size1/2); i++){
            aux = string1[i];
            string1[i] = string1[size1 -i-1];
            string1[size1 -i-1] = aux;
        }
        for(i=0;i<(size2/2); i++){
            aux = string2[i];
            string2[i] = string2[size2 -i-1];
            string2[size2 -i-1] = aux;
        }
        printf("A primeira string invertida fica: %s\n", string1);
        printf("A primeira string invertida fica: %s\n", string2);
        break;
    case 2:
        for(i=0; i<size1; i++){
            string3[i] = string1[i];
        }
        for(i=size1; i<(size2+size1); i++){
            string3[i] = string2[ i-size1];
        }
        string3[size2+size1] = '\0';
        printf("As string concatenadas gerou: %s\n", string3);
        break;
    case 3:
        if(size1>size2){
            printf("Primeira string\n");
        }
        else if(size1 < size2){
            printf("Segunda string\n");
        }else{
            printf("Mesmo tamanho\n");
        }
        break;
    case 4:
        if(size1>size2){
            printf("%s\n", string1);
        }
        else if(size1 < size2){
            printf("%s\n", string2);
        }else{
            printf("Mesmo tamanho string1: %s string2: %s\n", string1,string2);
        }
        break;
    case 5:

        printf("Por favor, digite o caractere que deseja procurar: ");
        caractere = getchar();
        while((getchar())!='\n');
        printf("%c\n", caractere);
        for(i=0;i<size1;i++){
            if(string1[i] ==caractere){
                posicao = i;
                printf("o caractere procurado está na posicao %d da primeira string\n", posicao);
                break;
            } 
        }
        for(i=0;i<size2;i++){
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