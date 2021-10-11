#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i,j,verificaNome=1;
    for(i=0;i<100;i++){
        for(j=0;j<strlen(primeiroNome);j++){
            if(!(contato[i].nome[j] == primeiroNome[j])){
                verificaNome =0;
            }
        }
        if(verificaNome){
            printf("ACHEI VC!!!!!");
        }
        verificaNome =1;
    }
    return 0;
}
