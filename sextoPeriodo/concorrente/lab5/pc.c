/* Disciplina: Programação Concorrente */
/* Prof.: Silvana Rossetto */
/* Produtor/consumidor usando semaforo binario e contador */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

#define PRODUTORES 10
#define CONSUMIDORES 10
#define MAX (PRODUTORES+CONSUMIDORES)
#define N 5 //numero de elementos no buffer

// Variaveis globais
sem_t slotCheio, slotVazio;  // semaforos para sincronizacao por condicao
sem_t mutexGeral; //semaforo geral de sincronizacao por exclusao mutua

int Buffer[N]; //buffer compartilhado

//imprime o buffer
void printBuffer(int buffer[], int tam) {
   for(int i=0;i<tam;i++) 
      printf("%d ", buffer[i]); 
   puts("");
}

//funcao para inserir um elemento no buffer
void Insere (int item, int id) {
   static int in=0;
   sem_wait(&slotVazio); //aguarda slot vazio para inserir
   sem_wait(&mutexGeral); //exclusao mutua entre produtores
   Buffer[in] = item; 
   in = (in + 1) % N;
   printf("Prod[%d]: inseriu %d\n", id, item);
   printBuffer(Buffer, N); //para log apenas
   sem_post(&mutexGeral);
   sem_post(&slotCheio); //sinaliza um slot cheio
}

//funcao para retirar  um elemento no buffer
int Retira (int id) {
   int item;
   static int out=0;
   sem_wait(&slotCheio); //aguarda slot cheio para retirar
   sem_wait(&mutexGeral); //exclusao mutua entre consumidores
   item = Buffer[out];
   Buffer[out] = 0;
   out = (out + 1) % N;
   printf("Cons[%d]: retirou %d\n", id, item);
   printBuffer(Buffer, N); //para log apenas
   sem_post(&mutexGeral);
   sem_post(&slotVazio); //sinaliza um slot vazio
   return item;
}

//----------------------------------------------------------
// Produtor 
void *produtor(void * arg) {
  int id = *(int *)(arg); 
  free(arg);
  while(1) {
    //produz alguma coisa....
    sleep(1);

    Insere(id, id); //insere o proximo item
  }
  pthread_exit(NULL);
}

//----------------------------------------------------------
// Consumidor
void *consumidor(void * arg) {
  int item, id = *(int *)(arg);
  free(arg);
  while(1) {
    item = Retira(id); //retira o proximo item
    
    //consome o item....
    sleep(1);
  }
  pthread_exit(NULL);
}

//--------------------------------------------------------------
// Funcao principal
int main(int argc, char **argv) {
  pthread_t tid[MAX];
  int i, *id;

  // Inicia os semaforos
  sem_init(&mutexGeral, 0, 1);
  sem_init(&slotCheio, 0, 0);
  sem_init(&slotVazio, 0, N);
  
  // Inicia os threads produtores
  for(i=0;i<PRODUTORES;i++) {
    id = (int *) malloc(sizeof(int));
    *id = i+1;
    if (pthread_create(&tid[i], NULL, produtor, (void *) (id))) {
      printf("Erro na criacao do thread produtor\n");
      exit(1);
    }
  }
  // Inicia os threads consumidores
  for(i=0;i<CONSUMIDORES;i++) {
    id = (int *) malloc(sizeof(int));
    *id = i+1;
    if (pthread_create(&tid[PRODUTORES+i], NULL, consumidor, (void *) (id))) {
      printf("Erro na criacao do thread produtor\n");
      exit(1);
    }
  }
  pthread_exit(NULL);
}        
