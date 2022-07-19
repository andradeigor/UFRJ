#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <iostream>

using namespace std;

int main(){
    char *linha = NULL;
    size_t tamLinha = 0;
    int vertices, arestas;
    scanf("%d %d\n", &vertices, &arestas);

    int *numAdj = (int *) malloc(sizeof(int) * vertices+1);
    int *numSaida = (int *) malloc(sizeof(int) * vertices+1);
    int **Adj = (int **) malloc(sizeof(int*) * vertices+1);
    for(int i = 1; i <= vertices; i++){
        Adj[i] = (int *)malloc(vertices+1 * sizeof(int));
        numAdj[i] =0;
        numSaida[i] = 0;
    }
    for(int i = 1; i <= vertices; i++){
        getline(&linha,&tamLinha,stdin);
        int pos = 0;
        int numLido = 0;
        int numChars;
        int lidos = 0;
    while (sscanf(&linha[pos], " %d %n", &numLido, &numChars) > 0) {
        pos += numChars;
        if(strlen(linha) != 0){
            Adj[i][lidos] = numLido; 
            lidos+=1;
            numSaida[i] +=1;
            numAdj[numLido]+=1; 
            }
        }
    }
    int *queue = (int *) malloc(sizeof(int) * vertices+1);
    int pointQueueEnd =0;
    int pointQueueStart =0;

    for(int i=1;i <= vertices;i++){
        if(numAdj[i] == 0){
            queue[pointQueueEnd] = i;
            pointQueueEnd +=1;
        }
    }
    while(pointQueueStart != pointQueueEnd){
        int actual = queue[pointQueueStart];
        cout << actual << " ";
        for(int k=0; k< numSaida[actual]; k++){
            int exitFromActual = Adj[actual][k];
            numAdj[exitFromActual] -=1;
            if(numAdj[exitFromActual] ==0){
                queue[pointQueueEnd] = exitFromActual;
                pointQueueEnd+=1;
            }
        }
        pointQueueStart +=1;
    }
    cout << endl;
    }









/*
        for(int k=0; k< numSaida[i]; k++){
            cout << Adj[i][k];
        }
        cout << endl;
    }

*/