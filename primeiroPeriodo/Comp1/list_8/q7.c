#include <stdio.h>

typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

int comparaTempo(TEMPO t1, TEMPO t2){
    int maior=0;
    if (t1.hora>t2.hora){
        maior = 1;
    }else if(t1.hora<t2.hora){
        maior = -1;
    }
    else if(t1.minuto>t2.minuto){
        maior = 1;
    }else if(t1.minuto<t2.minuto){
        maior = -1;
    }else if(t1.segundo>t2.segundo){
        maior = 1;
    }else if(t1.segundo<t2.segundo){
        maior = -1;
    }
    return maior;
}

int main(){
    TEMPO t1, t2;
    int maior;
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t1.hora,&t1.minuto,&t1.segundo);
    while(getchar()!='\n');
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t2.hora,&t2.minuto,&t2.segundo);
    while(getchar()!='\n');
    maior = comparaTempo(t1,t2);
    printf("A avaliação gerou: %d\n", maior);
    return 0;
}