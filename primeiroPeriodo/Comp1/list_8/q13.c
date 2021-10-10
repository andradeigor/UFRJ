#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _FRACAO{
    int numerador , denominador;
} FRACAO;


int soma(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if(fracao2->numerador ==0){
        fracao3->numerador =  fracao1->numerador;
        fracao3->denominador = fracao1->denominador;
        return 1;
    }
        if(fracao1->numerador ==0){
        fracao3->numerador =  fracao2->numerador;
        fracao3->denominador = fracao2->denominador;
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->denominador + fracao2->numerador * fracao1->denominador;
    fracao3->denominador = fracao2->denominador * fracao1->denominador;
    return 0;
}
int subtracao(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if(fracao2->numerador ==0){
        fracao3->numerador =  fracao1->numerador;
        fracao3->denominador = fracao1->denominador;
        return 1;
    }
        if(fracao1->numerador ==0){
        fracao3->numerador =  fracao2->numerador;
        fracao3->denominador = fracao2->denominador;
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->denominador - fracao2->numerador * fracao1->denominador;
    fracao3->denominador = fracao2->denominador * fracao1->denominador;
    return 0;
}
int produto(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if(fracao2->numerador ==0){
        fracao3->numerador =  fracao1->numerador;
        fracao3->denominador = fracao1->denominador;
        return 1;
    }
        if(fracao1->numerador ==0){
        fracao3->numerador =  fracao2->numerador;
        fracao3->denominador = fracao2->denominador;
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->numerador;
    fracao3->denominador = fracao2->denominador * fracao1->denominador;
    return 0;
}
int divisao(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if( fracao2->numerador ==0){
        printf("po, quando divide com numerador da fracao 2 como 0 gera divisão de 0, foi mal\n");
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->denominador;
    fracao3->denominador = fracao2->numerador * fracao1->denominador;
    return 0;
}
int main(){
    int i=0;
    FRACAO *fracoes;    
    fracoes = ( FRACAO *) malloc ( sizeof (FRACAO)*DIM);
    while (1){
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &((fracoes+i)->numerador), &((fracoes+i)->denominador));
        i++;
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &((fracoes+i)->numerador), &((fracoes+i)->denominador));
        i++;
        if((fracoes)->denominador ==0 || ((fracoes+1)->denominador ==0)){
            printf("Divisão por zero não dá.\n");
            i = i-2;
        }else{
            break;
        }
}
    
    printf("As fracoes são: %d/%d e %d/%d\n", (fracoes->numerador), (fracoes->denominador), ((fracoes+1)->numerador), ((fracoes+1)->denominador));
    soma(fracoes,fracoes+1, fracoes+i);
    printf("A soma dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    i++;
    subtracao(fracoes,fracoes+1, fracoes+i);
    printf("A subtração dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    i++;
    produto(fracoes,fracoes+1, fracoes+i);
    printf("A produto dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    i++;

    if(!divisao(fracoes,fracoes+1, fracoes+i)){
        printf("A divisao dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    }
    i++;
    return 0;
}
