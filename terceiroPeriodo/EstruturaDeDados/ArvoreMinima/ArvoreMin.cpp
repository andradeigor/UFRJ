#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <iostream>

using namespace std;


typedef struct Aresta{
    int vertice_1;
    int vertice_2;
    int peso;
} Aresta;

typedef struct Grupo{
    int tam;
    int pai;
}Grupo;


class Grafo{
    public:
        int arestas;
        int vertices;
        struct Aresta *ArestasList;
        Grafo(int A, int V){
            arestas = A;
            vertices = V;
            ArestasList = (Aresta *) malloc(sizeof(Aresta) * arestas);
        }
};

void merge(Aresta *array, int inicial, int meio, int final){
    int tamanhoDaEsquerda,tamanhoDaDireita, i ,topoDaEsquerda=0, topoDaDireita=0;
    Aresta *vetorDaEsquerda, *vetorDaDireita;

    tamanhoDaEsquerda = meio-inicial +1;
    tamanhoDaDireita = final-meio;

    vetorDaEsquerda = (Aresta *) malloc(tamanhoDaEsquerda * sizeof(Aresta));
    vetorDaDireita = (Aresta *) malloc(tamanhoDaDireita * sizeof(Aresta));

    for (i = 0; i < tamanhoDaEsquerda; i++){
        vetorDaEsquerda[i] = *(array + inicial+ i);
    }
    for (i = 0; i < tamanhoDaDireita; i++){
        vetorDaDireita[i] = *(array + meio+1+ i);
    }
    for (i =inicial; i <= final; i++){
        if(topoDaEsquerda >= tamanhoDaEsquerda){
            array[i] = vetorDaDireita[topoDaDireita];
            topoDaDireita ++;
        }
        else if(topoDaDireita >= tamanhoDaDireita){
            array[i] = vetorDaEsquerda[topoDaEsquerda];
            topoDaEsquerda++;
        }
        else if(vetorDaEsquerda[topoDaEsquerda].peso< vetorDaDireita[topoDaDireita].peso){
            array[i] = vetorDaEsquerda[topoDaEsquerda];
            topoDaEsquerda++;
        }
        else{
            array[i] = vetorDaDireita[topoDaDireita];
            topoDaDireita++;
        }
    }
    free(vetorDaEsquerda);
    free(vetorDaDireita);
    
}


void mergeSort( Aresta *array ,int inicial, int final){
    int meio;
    if(inicial < final){
        meio = (inicial + final)/2;
        mergeSort(array, inicial, meio);
        mergeSort(array, meio+1, final);
        merge(array, inicial, meio ,final);
    }
}

int find(Grupo *grupos, int i){
    if(grupos[i].pai != i ){
        grupos[i].pai = find(grupos, grupos[i].pai);// compressão de caminhos
    }
    return grupos[i].pai;
}

void Union(Grupo *grupos, int pai1, int pai2){
    if(grupos[pai1].tam < grupos[pai2].tam){
        grupos[pai1].pai = pai2;
        grupos[pai2].tam += grupos[pai1].tam; 
    }else{
        grupos[pai2].pai = pai1;
        grupos[pai1].tam += grupos[pai2].tam;
    }
}

void KruskalAGM(Grafo grafo){

    struct Grupo *ListaGrupos = (Grupo *) malloc((sizeof(Grupo) * grafo.vertices)+1);// + 1 pq os vertices começam em 1 então vou começar em 1 o indice pra minha cabeça não surtar
    
    for(int i=1; i<=grafo.vertices; i++){
        ListaGrupos[i].pai = i;
        ListaGrupos[i].tam = 1;
    }
    int Minimo =0;
    for(int i=0; i<grafo.arestas; i++){
        Aresta currentArresta = grafo.ArestasList[i];
        int pai1 = find(ListaGrupos, currentArresta.vertice_1);
        int pai2 = find(ListaGrupos, currentArresta.vertice_2);

        if(pai1!= pai2){
            Union(ListaGrupos, pai1, pai2);
            Minimo += currentArresta.peso;
        }
    }
    cout << Minimo << endl;

}


int main(){
    int vertices, arestas;
    scanf("%d %d\n", &vertices, &arestas);
    Grafo MainGrafo(arestas, vertices);
    for(int i =0; i<arestas; i++){
        int vertice1, vertice2, peso;
        scanf("%d %d %d", &vertice1 ,&vertice2,&peso);
        struct Aresta NewAresta;
        NewAresta.vertice_1 = vertice1;
        NewAresta.vertice_2 = vertice2;
        NewAresta.peso = peso; 
        MainGrafo.ArestasList[i] = NewAresta;
    }
    mergeSort(MainGrafo.ArestasList, 0, MainGrafo.arestas-1);
    KruskalAGM(MainGrafo);
    return 0;
}
