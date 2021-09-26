#include <stdio.h>


void Converter ( int numeroBase10 , int numeroBase2[32]) ;
int main (int argc , char *argv []){
    int nb10, nb2[32], i, teste = 1;
    while (1){
        scanf ("%d", &nb10);
        if (nb10<0) break;
        Converter(nb10, nb2);
        printf ("Teste % d\n", teste++);
        printf ("%d\n", nb10);
        /*loop para printar o valor em binário*/
        for(i=0; i<32; i++) printf ("%d", *(nb2+i));
        printf ("\n\n");
    }
    return 0;
}
void Converter(int numeroBase10, int numeroBase2[]){
    int resto,i=0,aux;
    /*fazemos o método de divisões sucessivas para calcular o valor em base 2*/
    while (numeroBase10!=0){
        resto = numeroBase10%2;
        numeroBase10 = numeroBase10/2;
        numeroBase2[i] = resto;
        i++;
    }
    /*Aqui, preenchemos o restante do vetor com o número 0, partindo de i(que foi a ultima posição usada pelo while)*/
    for(i=i; i<32; i++) numeroBase2[i] = 0;
    /*Quando fazemos o método de divisões sucessivas no papel, invertemos os resultados na hora da escrita*/
    /*Esse loop serve justamente para inverter o resultado da conta e do vetor como um todo.*/
    for(i=0;i<(32/2); i++){
        aux = numeroBase2[i];
        numeroBase2[i] = numeroBase2[32 -i-1];
        numeroBase2[32 -i-1] = aux;
    }

}