#include <stdio.h>

int main(){
    int pessoas=0,
    idadeAtual,
    idadeAcumulada=0,
    menorIdade=32767,
    maiorIdade=0;
    float idadeMedia;
    while(1){
        printf("Por favor, digite a idade. Idade com valor 0 indica o fim da leitura (ex:25): ");
        scanf("%d", &idadeAtual);
        while((getchar())!='\n');
        if(idadeAtual ==0) break;
        idadeAcumulada += idadeAtual;
        pessoas +=1;
        if(idadeAtual < menorIdade){
            menorIdade = idadeAtual;
        }
        else if (idadeAtual > maiorIdade){
            maiorIdade = idadeAtual;
        }
    }
    idadeMedia = idadeAcumulada/pessoas;
    printf("===================== \n");
    printf("O numero de pessoas lidas foi: %d \n", pessoas);
    printf("A idade media entre elas e: %1.1f \n", idadeMedia);
    printf("A menor idade entre elas e: %d \n", menorIdade);
    printf("A maior idade entra elas e: %d \n", maiorIdade);
    printf("===================== \n");
    return 0;
}