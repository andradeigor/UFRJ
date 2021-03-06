#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _FRACAO{
    int numerador , denominador;
} FRACAO;


FRACAO soma(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if(fracao2->numerador ==0){
        fracao3.numerador =  fracao1->numerador;
        fracao3.denominador = fracao1->denominador;
        return fracao3;
    }
        if(fracao1->numerador ==0){
        fracao3.numerador =  fracao2->numerador;
        fracao3.denominador = fracao2->denominador;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->denominador + fracao2->numerador * fracao1->denominador;
    fracao3.denominador = fracao2->denominador * fracao1->denominador;
    return fracao3;
}
FRACAO subtracao(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if(fracao2->numerador ==0){
        fracao3.numerador =  fracao1->numerador;
        fracao3.denominador = fracao1->denominador;
        return fracao3;
    }
        if(fracao1->numerador ==0){
        fracao3.numerador =  fracao2->numerador;
        fracao3.denominador = fracao2->denominador;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->denominador - fracao2->numerador * fracao1->denominador;
    fracao3.denominador = fracao2->denominador * fracao1->denominador;
    return fracao3;
}
FRACAO produto(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if(fracao2->numerador ==0){
        fracao3.numerador =  fracao1->numerador;
        fracao3.denominador = fracao1->denominador;
        return fracao3;
    }
        if(fracao1->numerador ==0){
        fracao3.numerador =  fracao2->numerador;
        fracao3.denominador = fracao2->denominador;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->numerador;
    fracao3.denominador = fracao2->denominador * fracao1->denominador;
    return fracao3;
}
FRACAO divisao(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if( fracao2->numerador ==0){
        printf("po, quando divide com numerador da fracao 2 como 0 gera divis??o de 0, foi mal\n");
        fracao3.numerador =   0;
        fracao3.denominador = 0;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->denominador;
    fracao3.denominador = fracao2->numerador * fracao1->denominador;
    return fracao3;
}
int main(){
    FRACAO fracao1, fracao2,fracSoma,fracSubtracao,fracProduto,fracDivisao;    
    while (1){
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &(fracao1.numerador), &(fracao1.denominador));
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &(fracao2.numerador), &(fracao2.denominador));
        if(fracao1.denominador ==0 || (fracao2.denominador ==0)){
            printf("Divis??o por zero n??o d??.\n");
        }else{
            break;
        }
}
    
    printf("As fracoes s??o: %d/%d e %d/%d\n", (fracao1.numerador), (fracao1.denominador), (fracao2.numerador), (fracao2.denominador));
    fracSoma = soma(&fracao1,&fracao2);
    printf("A soma d??: %d/%d\n", (fracSoma.numerador), (fracSoma.denominador));
    fracSubtracao = subtracao(&fracao1,&fracao2);
    printf("A subtra????o d??: %d/%d\n", (fracSubtracao.numerador), (fracSubtracao.denominador));
    fracProduto = produto(&fracao1,&fracao2);
    printf("A produto d??: %d/%d\n", (fracProduto.numerador), (fracProduto.denominador));
    fracDivisao = divisao(&fracao1,&fracao2);
    if(fracDivisao.denominador){
        printf("A divisao d??: %d/%d\n", (fracDivisao.numerador), (fracDivisao.denominador));
    }
    return 0;
}
