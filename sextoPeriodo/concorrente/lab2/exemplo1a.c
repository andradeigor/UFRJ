/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Codigo: Comunicação entre threads usando variável compartilhada e exclusao mutua com bloqueio */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define NTHREADS  2

int soma = 0; //variavel compartilhada entre as threads
pthread_mutex_t mutex; //variavel de lock para exclusao mutua

//funcao executada pelas threads
void *ExecutaTarefa (void *threadid) {
  int i, tid = *(int*) threadid;
  printf("Thread : %d esta executando...\n", tid);
  for (i=0; i<100000; i++) {
     //--entrada na SC
     pthread_mutex_lock(&mutex);
     //--SC
     soma++; //incrementa o contador de tarefas realizadas 
     //--saida da SC
     pthread_mutex_unlock(&mutex);
  }
  printf("Thread : %d terminou!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t tid[NTHREADS];
  int t, id[NTHREADS];

  //--inicilaiza o mutex (lock de exclusao mutua)
  pthread_mutex_init(&mutex, NULL);

  for(t=0; t<NTHREADS; t++) {
    id[t]=t;
    if (pthread_create(&tid[t], NULL, ExecutaTarefa, (void *) &id[t])) {
      printf("--ERRO: pthread_create()\n"); exit(-1);
    }
  }
  //--espera todas as threads terminarem
  for (t=0; t<NTHREADS; t++) {
    if (pthread_join(tid[t], NULL)) {
         printf("--ERRO: pthread_join() \n"); exit(-1); 
    } 
  } 
  pthread_mutex_destroy(&mutex);

  //--imprime a variavel de saida
  printf("Valor de soma = %d\n", soma);
}
