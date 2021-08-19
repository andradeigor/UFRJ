#include <stdio.h>

int main(){
    int numColunas,
    confereColunas=0,
    numLinhas, 
    confereLinhas=0,
    linhas,
    colunas;
    while(confereColunas==0){
        printf("Por favor, digite o numero de colunas da impressão (ex: 10): ");
        scanf("%d", &numColunas);
        while((getchar())!='\n');
        confereColunas = 1;
    }
    while(confereLinhas==0){
        printf("Por favor, digite o numero de Linhas da impressão (ex: 10): ");
        scanf("%d", &numLinhas);
        while((getchar())!='\n');
        confereLinhas = 1;
    }
    for(linhas=1; linhas<=numLinhas; linhas++ ){
        for(colunas=1;colunas<=numColunas;colunas++){
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}