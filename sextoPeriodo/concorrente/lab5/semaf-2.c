/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Codigo: Comunicação entre threads usando variável compartilhada e sincronização com semáforos */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS 3

// Variaveis globais
int x = 0;      //variavel compartilhada entre as threads
sem_t condt2, condt3;     //semaforos para sincronizar a ordem de execucao das threads

//funcao executada pela thread 1
void *t1 (void *threadid) {
  int *tid = (int*) threadid;
  printf("Thread : %d esta executando...\n", *tid);
  x = 1;
  sem_post(&condt2); //permite que T2 execute
  printf("Thread : %d terminou!\n", *tid);
  pthread_exit(NULL);
}

//funcao executada pela thread 2
void *t2 (void *threadid) {
  int *tid = (int*) threadid;
  printf("Thread : %d esta executando...\n", *tid);
  sem_wait(&condt2); //espera T1 executar
  x = 2;
  sem_post(&condt3); //permite que T3 execute
  printf("Thread : %d terminou!\n", *tid);
  pthread_exit(NULL);
}

//funcao executada pela thread 3
void *t3 (void *threadid) {
  int *tid = (int*) threadid;
  printf("Thread : %d esta executando...\n", *tid);
  sem_wait(&condt3); //espera T2 executar
  printf("Valor de x = %d\n", x);
  printf("Thread : %d terminou!\n", *tid);
  pthread_exit(NULL);
}

//funcao principal
int main(int argc, char *argv[]) {
  pthread_t tid[NTHREADS];
  int *id[3], t;

  for (t=0; t<NTHREADS; t++) {
    if ((id[t] = malloc(sizeof(int))) == NULL) {
       pthread_exit(NULL); return 1;
    }
    *id[t] = t+1;
  }

  //inicia os semaforos
  sem_init(&condt2, 0, 0);
  sem_init(&condt3, 0, 0);

  //cria as tres threads
  if (pthread_create(&tid[1], NULL, t2, (void *)id[1])) { 
	  printf("--ERRO: pthread_create()\n"); exit(-1); }
  if (pthread_create(&tid[2], NULL, t3, (void *)id[2])) { 
	  printf("--ERRO: pthread_create()\n"); exit(-1); }
  if (pthread_create(&tid[0], NULL, t1, (void *)id[0])) { 
	  printf("--ERRO: pthread_create()\n"); exit(-1); }

  //--espera todas as threads terminarem
  for (t=0; t<NTHREADS; t++) {
    if (pthread_join(tid[t], NULL)) {
         printf("--ERRO: pthread_join() \n"); exit(-1); 
    } 
    free(id[t]);
  } 
  pthread_exit(NULL);
}
