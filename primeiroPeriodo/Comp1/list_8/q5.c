#include <stdio.h>

typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

TEMPO maiorTempo(TEMPO t1, TEMPO t2){
    int maior;
    if (t1.hora>t2.hora){
        maior = 1;
    }else if(t1.hora<t2.hora){
        maior = 2;
    }
    else if(t1.minuto>t2.minuto){
        maior = 1;
    }else if(t1.minuto<t2.minuto){
        maior = 2;
    }else if(t1.segundo>t2.segundo){
        maior = 1;
    }else{
        maior = 2;
    }
    return maior == 1? t1:t2;
}

int main(){
    TEMPO t1, t2,t3;
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t1.hora,&t1.minuto,&t1.segundo);
    while(getchar()!='\n');
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t2.hora,&t2.minuto,&t2.segundo);
    while(getchar()!='\n');
    t3 = maiorTempo(t1,t2);
    printf("O maior tempo é %d:%d:%d\n", t3.hora,t3.minuto,t3.segundo);
    return 0;
}