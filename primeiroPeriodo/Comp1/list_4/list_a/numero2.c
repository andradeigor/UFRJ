#include <stdio.h>

int main(){
    int numLinhas, 
    confereLinhas=0,
    linhas,
    j;

    while(confereLinhas==0){
        printf("Por favor, digite o numero de Linhas da impressão (ex: 10): ");
        scanf("%d", &numLinhas);
        while((getchar())!='\n');
        confereLinhas = 1;
    }
    for(linhas=1; linhas<=numLinhas; linhas++ ){
        for(j=0; j<linhas;j++){
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}