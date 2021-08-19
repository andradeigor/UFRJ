#include <stdio.h>
#define DIM1 2
#define DIM2 3

int main(void){
    int matriz1[DIM1][DIM2],
    matriz2[DIM1][DIM2],
    matriz3[DIM1][DIM2],i,j;
    for(i=0;i<DIM1;i++){
        for(j=0;j<DIM2;j++){
            printf("Por favor, digite o numero que deseja na posição [%d,%d] da primeira matrix: ", i,j);
            scanf("%d", &matriz1[i][j]);
            while((getchar())!='\n');  
            printf("Por favor, digite o numero que deseja na posição [%d,%d] da segunda matrix: ", i,j);
            scanf("%d", &matriz2[i][j]);
            while((getchar())!='\n');
            matriz3[i][j] = matriz1[i][j] +matriz2[i][j];
        }
    }
    printf("A soma gerada foi: \n");
    for(i=0;i<DIM1;i++){
        for(j=0;j<DIM2;j++){
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }
    return 0;
}