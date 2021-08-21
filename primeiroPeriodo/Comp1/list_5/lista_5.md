Nome: Igor de Andrade Assunção de Almeida

DRE:121095736

Atividade: Lista 5

Questão1

1) Escreva um programa em C que leia duas strings do teclado e, através de um menu, faça:


    a. Mostre as strings invertidas;

    b. Copie (ou concatene) as duas strings em outro vetor, imprimindo a resposta;

    c. Compare as duas strings e informe quem é a string maior;
    d. Informe a string de maior tamanho;

    e. Identifique a ocorrência de determinado caractere na string e informa sua posição (não se esqueça de solicitar o caractere);

```
#include <stdio.h>
#define DIM 21

int main(void){
    char string1[DIM],
    string2[DIM],
    string3[DIM*2],
    aux,
    caractere;

    int i,
    opcao, posicao,
    size1=0,size2=0;

    printf("Por favor, digite uma string de até 20 caracteres: ");
    fgets(string1, DIM, stdin);
    for(i=0; i<DIM; i++){
        size1 += 1;
        if(string1[i] == '\n' ||string1[i] == '\0') {
            size1 -= 1; //off by one por causa do \0 ser contado como "tamanho", esse -1 arruma isso
            string1[i] = '\0';
            break;
            }
    }
    printf("Por favor, digite uma segunda string de até 20 caracteres: ");
    fgets(string2, DIM, stdin);
    for(i=0; i<DIM; i++){
        size2 += 1;
        if(string2[i] == '\n' ||string2[i] == '\0') {
            size2 -=1 ;//off by one por causa do \0 ser contado como "tamanho", esse -1 arruma isso
            string2[i] = '\0';
            break;
        }
    }
    printf("Por favor, digite a opção desejada:\n");
    printf("1. Mostre as strings invertidas;\n");
    printf("2. Copie (ou concatene) as duas strings em outro vetor, imprimindo a resposta;\n");
    printf("3. Compare as duas strings e informe quem é a string maior;\n");
    printf("4. Informe a string de maior tamanho;\n");
    printf("5. Identifique a ocorrência de determinado caractere na string e informa sua posicao;\n");
    while(1){
        scanf("%d", &opcao);
        while((getchar())!='\n');
        if(opcao >=1 && opcao<=5){
            break;
        }    
    }
    switch (opcao)
    {
    case 1:
        for(i=0;i<(size1/2); i++){
            aux = string1[i];
            string1[i] = string1[size1 -i-1];
            string1[size1 -i-1] = aux;
        }
        for(i=0;i<(size2/2); i++){
            aux = string2[i];
            string2[i] = string2[size2 -i-1];
            string2[size2 -i-1] = aux;
        }
        printf("A primeira string invertida fica: %s\n", string1);
        printf("A primeira string invertida fica: %s\n", string2);
        break;
    case 2:
        for(i=0; i<size1; i++){
            string3[i] = string1[i];
        }
        for(i=size1; i<(size2+size1); i++){
            string3[i] = string2[ i-size1];
        }
        string3[size2+size1] = '\0';
        printf("As string concatenadas gerou: %s\n", string3);
        break;
    case 3:
        if(size1>size2){
            printf("Primeira string\n");
        }
        else if(size1 < size2){
            printf("Segunda string\n");
        }else{
            printf("Mesmo tamanho\n");
        }
        break;
    case 4:
        if(size1>size2){
            printf("%s\n", string1);
        }
        else if(size1 < size2){
            printf("%s\n", string2);
        }else{
            printf("Mesmo tamanho string1: %s string2: %s\n", string1,string2);
        }
        break;
    case 5:

        printf("Por favor, digite o caractere que deseja procurar: ");
        caractere = getchar();
        while((getchar())!='\n');
        printf("%c\n", caractere);
        for(i=0;i<size1;i++){
            if(string1[i] ==caractere){
                posicao = i;
                printf("o caractere procurado está na posicao %d da primeira string\n", posicao);
                break;
            } 
        }
        for(i=0;i<size2;i++){
            if(string2[i] ==caractere){
                posicao = i;
                printf("o caractere procurado está na posicao %d da segunda string\n", posicao);
                return 0;
            } 
        }
        printf("O caractere informado nao esta presente nas strings\n");
    default:
        break;
    }

    return 0;
}

```

2) Faça um programa que leia duas matrizes (2x3) de números inteiros e imprima a soma das matrizes.

```
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
```

3) Crie um programa que lê uma sequência de 10 números inteiros e informa:

    a. o maior valor da lista;

    b. o menor valor da lista;

    c. quantos valores são pares;

    d. a soma de todos os valores;

    e. ao usuário se um determinado valor está no vetor ou não.

```
#include <stdio.h>
#define DIM 10

int main(void){
    int i,numeros[DIM],maior=0,menor=32767,pares=0, soma=0,numeroProcurado;
    for(i=0; i<DIM;i++){
        printf("Por favor, digite o % dº numero: ", i+1);
        scanf("%d", &numeros[i]);
        if(numeros[i] > maior) maior=numeros[i];
        if(numeros[i] < menor) menor=numeros[i];
        if(numeros[i]%2 == 0) pares+=1;
        soma+=numeros[i];
    }
    printf("por valor, digite o numero que deseja procurar na lista: ");
    scanf("%d", &numeroProcurado);
    for(i=0; i<DIM;i++){
        if(numeros[i] == numeroProcurado){
            printf("O numero procurado (%d) existe na lista e está na posicao %d \n", numeroProcurado, i);
        }
    }
    printf("O maior valor da lista e:%d \n", maior);
    printf("O menor valor da lista e:%d \n", menor);
    printf("%d numeros dos digitados sao pares \n", pares);
    printf("a soma de valores e: %d \n", soma);
    return 0;
}
``` 

4) Faça um programa que leia duas matrizes (5x5) de números inteiros, calcule e imprima o resultado da multiplicação entre as duas matrizes.

```
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
```

5) Leia dois vetores de inteiros x e y, cada um com 5 elementos (assuma que o usuário não informa elementos repetidos). Calcule e mostre os vetores resultantes em cada caso abaixo:

    a. Soma entre x e y: soma de cada elemento de x com o elemento da mesma posição em y;

    b. Produto entre x e y: multiplicação de cada elemento de x com o elemento da mesma posição em y;

    c. Diferença entre x e y: todos os elementos de x que não existam em y;

    d. Interseção entre x e y: apenas os elementos que aparecem nos dois vetores;

    e. União entre x e y: todos os elementos de x, e todos os elementos de y que não estão em x.

```
#include <stdio.h>
#define DIM 5
int main(void){
    int i,j,x[DIM],
    y[DIM],soma[DIM],
    produto[DIM],diferenca[DIM],
    diferencaIndex=0,intersecao[DIM], 
    intersecaoIndex=0,uniao[DIM*2],k,existINT=0,existUN=0,
    existX,existY,indexUniao=0;
    for(i=0;i<DIM;i++){
        printf("Por favor, digite o %dº numero para o vetor x: ", i+1);
        scanf("%d", &x[i]);
        while((getchar())!='\n');  
        printf("Por favor, digite o %dº numero para o vetor y: ", i+1);
        scanf("%d", &y[i]);
        while((getchar())!='\n');
        soma[i] = x[i] + y[i];
        produto[i] = x[i] * y[i];
        for(k=0;k<i;k++){
            if(uniao[k]==x[i]) existUN=1;
        }
        if(!existUN){
            uniao[indexUniao] = x[i];
            indexUniao+=1;
        }
        existUN=0;
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
                for(k=0;k<intersecaoIndex;k++){
                    if(x[i] == intersecao[k]) {
                        existINT=1;
                    }
                }
                if(!existINT){
                intersecao[intersecaoIndex] = x[i];
                intersecaoIndex +=1;
                }
                existX=1;
                existINT=0;
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
```


6) Faça um programa que leia uma matriz de 5 linhas e 4 colunas contendo as seguintes informações sobre alunos de uma disciplina, sendo todas as informações do tipo inteiro:

    Primeira coluna: numero de matrícula (use um inteiro)

    Segunda coluna: media das provas

    Terceira coluna: media dos trabalhos

    Quarta coluna: nota final 

    Elabore um programa que:

    a. Leia as três primeiras informações de cada aluno;

    b. Calcule a nota final como sendo a soma da media das provas e da média dos trabalhos;

    c. Imprima a matrícula do aluno que obteve a maior nota final (assuma que só existe uma maior nota);

    d. Imprima a média aritmética das notas finais.

```
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
    printf("A media de notas finais foi %1.1f\n",mediaNotaFinal/DIM1);

    return 0;
}
```