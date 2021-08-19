#include <stdio.h>
#define DIM1 5
#define DIM2 5

int main(void){
    int matriz1[DIM1][DIM2],
    matriz2[DIM1][DIM2],
    matriz3[DIM1][DIM2],i,j,k;
    for(i=0;i<DIM1;i++){
        for(j=0;j<DIM2;j++){
            printf("Por favor, digite o numero que deseja na posição [%d,%d] da primeira matrix: ", i,j);
            scanf("%d", &matriz1[i][j]);
            while((getchar())!='\n');  
            printf("Por favor, digite o numero que deseja na posição [%d,%d] da segunda matrix: ", i,j);
            scanf("%d", &matriz2[i][j]);
            while((getchar())!='\n');
        }
    }
    for(i=0;i<DIM1;i++){
        for(j=0;j<DIM2;j++){
            matriz3[i][j] = 0;
            for(k=0;k<DIM2;k++){
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j]; 
            }
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }
    
}