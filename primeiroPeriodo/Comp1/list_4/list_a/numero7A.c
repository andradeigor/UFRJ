#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Os numeros recebidos variam entrem torno de 1M, e as porcentagens em volta de 16,69 +/-5. Bem preciso também
*/
int main(){
    int i;

    float x,
        y,
        pi=0;
    
    srand(time(NULL));
    for (i=0; i<1000000; i++){
        x = rand();
        x = x/(RAND_MAX);
        y = rand();
        y = y/(RAND_MAX);
        /*
        qualquer que seja x e y dentre [0,1], se a soma dos quadrados for maior que 1 a raiz
        a raiz quadrada dessa soma tambem sera maior que um.
        e se a soma dos quadrados for menor que 1, a raiz tambem sera.
        Por isso que nesse caso não é necessário tirar a raiz quadrada para calcular a distancia do
        ponto x,y para a base 0,0;
        */
        if((x*x + y*y) <=1){
            pi +=1;
        }
    }
    pi = (pi*4)/1000000;
    printf("o numero de pi calculado foi %1.6f \n", pi);
    return 0;
}
