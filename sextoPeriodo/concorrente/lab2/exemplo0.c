/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Codigo: Threads escrevem e leem uma variavel global: exemlo de programa com condicao de corrida */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define NTHREADS 3

int x = 0; //variavel compartilhada entre as threads

//funcao executada pela thread 1
void *t1 (void *arg) {
  long int id = (long int) arg;
  printf("Thread : %ld esta executando...\n", id);
  x = 1;
  printf("Thread : %ld terminou!\n", id);
  pthread_exit(NULL);
}

//funcao executada pela thread 2
void *t2 (void *arg) {
  long int id = (long int) arg;
  printf("Thread : %ld esta executando...\n", id);
  x = 2;
  printf("Thread : %ld terminou!\n", id);
  pthread_exit(NULL);
}

//funcao executada pela thread 3
void *t3 (void *arg) {
  int y;
  long int id = (long int) arg;
  printf("Thread : %ld esta executando...\n", id);
  y = x;
  printf("Valor de y = %d\n", y);
  printf("Thread : %ld terminou!\n", id);
  pthread_exit(NULL);
}

//fluxo principal
int main(int argc, char *argv[]) {
  pthread_t tid[NTHREADS];
  long int id; 
  //cria as 3 threads
  id=2;
  if (pthread_create(&tid[1], NULL, t2, (void *)id)) return 1; 
  id=1;
  if (pthread_create(&tid[0], NULL, t1, (void *)id)) return 1;
  id=3;
  if (pthread_create(&tid[2], NULL, t3, (void *)id)) return 1;

  pthread_exit(NULL);
  return 0;
}
