#include <stdio.h>
#define DIM 5
int main(void){
    int i,j,x[DIM],
    y[DIM],soma[DIM],
    produto[DIM],diferenca[DIM],
    diferencaIndex=0,intersecao[DIM], 
    intersecaoIndex=0,uniao[DIM*2],
    existX,existY,indexUniao=DIM;
    for(i=0;i<DIM;i++){
        printf("Por favor, digite o %dº numero para o vetor x: ", i+1);
        scanf("%d", &x[i]);
        while((getchar())!='\n');  
        printf("Por favor, digite o %dº numero para o vetor y: ", i+1);
        scanf("%d", &y[i]);
        while((getchar())!='\n');
        soma[i] = x[i] + y[i];
        produto[i] = x[i] * y[i];
        uniao[i] = x[i];    
    }
    printf("==========================\n");
    for (i=0;i<DIM;i++){
        printf("a soma entre %d e %d da %d, seu produto da %d \n",x[i],y[i],soma[i],produto[i]);
    }
    printf("==========================\n");
    for (i=0;i<DIM;i++){
        existX=0;
        existY=0;
        for (j=0;j<DIM;j++){
            if(x[i] == y[j] ){
                intersecao[intersecaoIndex] = x[i];
                intersecaoIndex +=1;
                existX=1;
            }
            if(y[i] ==x[j]){
                existY =1;
            }
        }
        if(!existX){
            diferenca[diferencaIndex] = x[i];
            diferencaIndex +=1;
        }
        if(!existY){
            uniao[indexUniao] = y[i];
            indexUniao +=1;
        }
    }
    printf("a interseção de x com y é: ");
    for ( i = 0; i < intersecaoIndex; i++){
        printf("%d ", intersecao[i]);
    }
    printf("\na diferenca de x com y é: ");
    for ( i = 0; i < diferencaIndex; i++){
        printf("%d ", diferenca[i]);
    }
    printf("\na uniao de x com y é: ");
    for ( i = 0; i < indexUniao; i++){
        printf("%d ", uniao[i]);
    }
    printf("\n==========================\n");
    return 0;
}