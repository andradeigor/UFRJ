#include <stdio.h>

/*
considerando que o mesmo cálculo será feito para os dois, é simples:
multiplicar os anos por 365 e meses por 30. Mesmo que esse não de o numero
correto de dias vividos, como ambos são multiplicados pelos mesmos numero
será possivel saber quem é mais velho e inclusive se nasceram no mesmo dia.
Mesmo que, em teoria, o cálculo esteja errado. É uma forma bem rudimentar de 
calcular algo próximo de Unix time.
*/
int main(void){
    int dia1,mes1,ano1,dia2,mes2,ano2, 
        pessoa1,pessoa2, confereData1=0,
        confereData2=0;
    while(confereData1==0){
        printf("Por favor, digite a data de nascimento da primeira pessoa(ex: 1 2 1980): ");
        scanf("%d %d %d", &dia1,&mes1,&ano1);
        while((getchar())!='\n');
        if((dia1<=31 && dia1 > 0) && (mes1 <=12 && mes1 >0)){
            confereData1=1;
        }
    }
    while(confereData2==0){
        printf("Por favor, digite a data de nascimento da segunda pessoa(ex: 1 2 1980): ");
        scanf("%d %d %d", &dia2,&mes2,&ano2);
        while((getchar())!='\n');
        if((dia2<=31 && dia2 > 0) && (mes2 <=12 && mes2 >0)){
            confereData2=1;
        }
    }
    pessoa1 = ano1*365 + mes1 * 30 + dia1;
    pessoa2 = ano2*365 + mes2 * 30 + dia2;
    if(pessoa1< pessoa2){
       printf("Primeiro! \n");
    }else if(pessoa1>pessoa2){
        printf("Segundo! \n");
    }else{
        printf("Mesmo dia! \n");
    }
    return 0;
}