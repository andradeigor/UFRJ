#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Os numeros recebidos variam entrem torno de 1M, e as porcentagens em volta de 16,69 +/-5. Bem preciso também
*/
int main(){
    int i, 
        n;
    float numero1=0.0,
        numero2=0.0,
        numero3=0.0,
        numero4=0.0,
        numero5=0.0,
        numero6=0.0,
        porcentagem1=0.00,
        porcentagem2=0.00,
        porcentagem3=0.00,
        porcentagem4=0.00,
        porcentagem5=0.00,
        porcentagem6=0.00;

    srand(time(NULL));
    for (i=0; i<6000000; i++){
        n= rand();
        n = n%6 + 1;
        switch (n){
            case 1:
                numero1+=1;
                break;
            case 2:
                numero2+=1;
                break;
            case 3:
                numero3+=1;
                break;
            case 4:
                numero4+=1;
                break;
            case 5:
                numero5+=1;
                break;
            case 6:
                numero6+=1;
                break;
        }
    }
    porcentagem1 = (numero1/6000000)*100.0;
    porcentagem2 = (numero2/6000000)*100.0;
    porcentagem3 = (numero3/6000000)*100.0;
    porcentagem4 = (numero4/6000000)*100.0;
    porcentagem5 = (numero5/6000000)*100.0;
    porcentagem6 = (numero6/6000000)*100.0;

    printf("O numero 1 saiu %1.0f vezes e teve %1.2f porcento de frequencia \n", numero1,porcentagem1);
    printf("O numero 2 saiu %1.0f vezes e teve %1.2f porcento de frequencia \n", numero2,porcentagem2);
    printf("O numero 3 saiu %1.0f vezes e teve %1.2f porcento de frequencia \n", numero3,porcentagem3);
    printf("O numero 4 saiu %1.0f vezes e teve %1.2f porcento de frequencia \n", numero4,porcentagem4);
    printf("O numero 5 saiu %1.0f vezes e teve %1.2f porcento de frequencia \n", numero5,porcentagem5);
    printf("O numero 6 saiu %1.0f vezes e teve %1.2f porcento de frequencia \n", numero6,porcentagem6);
    return 0;
}
