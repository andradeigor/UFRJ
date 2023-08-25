/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 2 - Laboratório: 1 */
/* Codigo: "Hello World" usando threads em C e a funcao que espera as threads terminarem */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define NTHREADS  10 //total de threads a serem criadas

//cria a estrutura de dados para armazenar os argumentos da thread
typedef struct {
   int idThread, nThreads;
} t_Args;

//funcao executada pelas threads
void *PrintHello (void *arg) {
  t_Args *args = (t_Args *) arg;

  printf("Sou a thread %d de %d threads\n", args->idThread, args->nThreads);
  free(arg); //libera a alocacao feita na main

  pthread_exit(NULL);
}

//funcao principal do programa
int main() {
  pthread_t tid_sistema[NTHREADS]; //identificadores das threads no sistema
  t_Args *args; //receberá os argumentos para a thread

  for(int i=0; i<NTHREADS; i++) {
    printf("--Aloca e preenche argumentos para thread %d\n", i);
    args = malloc(sizeof(t_Args));
    if (args == NULL) {
      printf("--ERRO: malloc()\n"); exit(-1);
    }
    args->idThread = i; 
    args->nThreads = NTHREADS; 
    
    printf("--Cria a thread %d\n", i);
    if (pthread_create(&tid_sistema[i], NULL, PrintHello, (void*) args)) {
      printf("--ERRO: pthread_create()\n"); exit(-1);
    }
  }

  //--espera todas as threads terminarem
  for (int i=0; i<NTHREADS; i++) {
    if (pthread_join(tid_sistema[i], NULL)) {
         printf("--ERRO: pthread_join() \n"); exit(-1); 
    } 
  }

  printf("--Thread principal terminou\n");
  pthread_exit(NULL);
}
