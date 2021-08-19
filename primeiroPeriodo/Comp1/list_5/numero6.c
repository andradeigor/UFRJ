#include <stdio.h>
#define DIM1 5
#define DIM2 4

int main(void){
    int i,j,matriculaMaiorNota;
    
    float notafinal, matrix[DIM1][DIM2],
    maiorNota=0,mediaNotaFinal=0;
    
    for(i =0; i<DIM1;i++){
        for(j=0;j<DIM2-1;j++){
            switch (j)
            {
            case 0:
                while(1){
                printf("Por favor, aluno %d digite seu numero de matricula: ",i+1);
                scanf("%f", &matrix[i][j]);
                if(matrix[i][j] >0) break;
                }
                break;
            case 1:
                while(1){
                    printf("Por favor, aluno %d digite sua média nas provas: ",i+1);
                    scanf("%f", &matrix[i][j]);
                    if(matrix[i][j] >=0 && matrix[i][j] <=10) break;
                }

                break;
            case 2:
                while(1){
                    printf("Por favor, aluno %d digite sua média nos trabalhos: ",i+1);
                    scanf("%f", &matrix[i][j]);
                    if(matrix[i][j] >=0 && matrix[i][j] <=10) break;
                }
            case 3:
                notafinal = (matrix[i][1] + matrix[i][2])/2;
                matrix[i][3] = notafinal;
                mediaNotaFinal += notafinal;
                if(notafinal> maiorNota){
                    maiorNota = notafinal;
                    matriculaMaiorNota = matrix[i][0];
                }   
                break;
            default:
                break;
            }
        }
    }
    printf("O aluno com matricula %d foi o aluno que teve a maior nota!!!\n", matriculaMaiorNota);
    printf("A media de notas finais foi %f\n",mediaNotaFinal/DIM1);

    return 0;
}