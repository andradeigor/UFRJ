#include <stdio.h>

void conta_vogais (char string [], int vogais []);
int main(){
    int size,
    i,
    realSize=0;
    
    printf("por favor, digite o tamanho do vetor: ");
    scanf("%d", &size);
    
    size +=1; /* contando com o \0*/ 
    while(getchar() != '\n');
    char word[size];
    printf("por favor, digite uma palavra de até %d caracteres: ", size-1);
    fgets(word, size, stdin);
    
    for(i=0;i<size;i++){
        realSize+=1;
        if(word[i] == '\n'){
            word[i] = '\0';
            realSize-=1;
            break;
        }
    }
    conta_vogais
    printf("%d, %s \n", realSize, word);
    return 0;
}