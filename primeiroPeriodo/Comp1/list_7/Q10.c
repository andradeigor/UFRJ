#include <stdio.h>
#include <stdlib.h>

int merge(int *array, int comeco, int meio, int fim){
    /* os tamanhos serão calculados com base nos índices*/
    /* os topos apontarão para onde cada pilha está olhando*/
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;
    int *vetorEsquerda,*vetorDireita;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;
    /*alocamos dinâmicamente o espaço para as arrays e liberamos após a execução da função*/
    vetorEsquerda = (int *) malloc (tamanhoEsquerda*sizeof( int ));
    vetorDireita = (int *) malloc (tamanhoDireita*sizeof( int )); 
    /*cria as subarrays com base no tamanho da lista original*/
    /*preenchemos as subarrays com os elementos da lista original, para ordenar */
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
    }
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
    }
    /* aqui, ordenamos de comeco até o fim a cada interação só entramos em um dos if, por isso os else ifs e else no final*/
    for(i=comeco;i<=(fim);i++){
        /* os dois primeiros ifs servem para verificar se já esgotamos a pilha da esquerda ou direita*/
        /* caso tenhamos esgotado, resta adicionar a pilha oposta ao restante da array original*/
        if(topoEsquerda >= tamanhoEsquerda){
            array[i] = vetorDireita[topoDireita];
            topoDireita ++;
        }
        else if(topoDireita >= tamanhoDireita){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        /* aqui, é o caso que nenhum dos topos se esgotou, verificamos se o elemento da esquerda é menor, se for adiciona ele.*/
        else if(vetorEsquerda[topoEsquerda]< vetorDireita[topoDireita]){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        /* aqui seria o caso que o da direita é menor, então adicionamos ele a array original e aumentamos o valor da pilha*/
        else{
            array[i] = vetorDireita[topoDireita];
            topoDireita++;
        }
    }
    free(vetorEsquerda);
    free(vetorDireita);
    return 0;
}

int mergeSort( int *array, int comeco, int fim){
    /*essa função é uma auxiliar, ela existe para dividir a array maior em subarrays.
    Inicialmente, a array que ia de [0:n] virou:
    array1[0:n/2], array2[n/2:0] em notação com ultimo elemento exclusivo*/
    int meio;
    if(comeco<fim){
        meio = (comeco+fim)/2;
        mergeSort(array,comeco,meio);
        mergeSort(array,meio+1,fim);
        merge(array, comeco, meio, fim);
    }
    return 0;
}


int main(){
    int i,n,*array;
    printf("Por favor, digite o tamanho do vetor: ");
    scanf ("%d", &n);
    
    /* aloca espaco na memoria para n elementos*/
    array = (int *) malloc (n*sizeof( int ));
    if(!array) {
        puts("Sem memoria.");
        return 1;
    }
    for ( i = 0; i < n; i++){
        printf("Por favor, digite o elemento %dº do vetor: ", i+1);
        scanf("%d", array+i);
    }
    /*Chama a função que de fato vai ordenar, passando index do primeiro e do ultimo elemento,
     uma array de tamanho n tem n-1 como ultimo index*/
    mergeSort(array, 0, n-1);
    /*Printa os elementos ordenados.*/
    for(i=0;i<n;i++){
        printf("%d ", array[i]);
    }
    free(array);
    printf("\n");
    return 0;
}
