#include <stdio.h>

typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

TEMPO maiorTempo(TEMPO t1, TEMPO t2){
    TEMPO t3;
    /* o compilador reclama que a variável não foi inicializada, precisei iniciar os valores como 0 mesmo sendo feio*/
    t3.hora = 0;
    t3.minuto = 0;
    t3.segundo = 0;
    if(t1.segundo+t2.segundo >= 60){
        t3.minuto += (t1.segundo+t2.segundo)/60;
        t3.segundo += (t1.segundo+t2.segundo)%60;
    }else{
        t3.segundo = t1.segundo + t2.segundo;
    }
    if(t1.minuto+t2.minuto >= 60){
        t3.hora += (t1.minuto+t2.minuto)/60;
        t3.minuto += (t1.minuto+t2.minuto)%60;
    }else{
        t3.minuto = t1.minuto + t2.minuto;
    }
    t3.hora += t1.hora + t2.hora;
    return t3;
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
    printf("A soma dos tempos é %d:%d:%d\n", t3.hora,t3.minuto,t3.segundo);
    return 0;
}