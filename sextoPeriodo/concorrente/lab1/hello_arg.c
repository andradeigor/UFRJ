/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 2 - Laboratório: 1 */
/* Codigo: "Hello World" usando threads em C com passagem de um argumento */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define NTHREADS  10 //total de threads a serem criadas

//funcao executada pelas threads
void *PrintHello (void* arg) {
  long int idThread = (long int) arg;

  printf("Hello World da thread: %ld\n", idThread);

  pthread_exit(NULL);
}

//funcao principal do programa
int main(void) {
  pthread_t tid_sistema[NTHREADS]; //identificadores das threads no sistema

  printf("Tamanho ponteiro:%ld bytes\n", sizeof(void*));
  printf("Tamanho int:%ld bytes\n", sizeof(int));
  printf("Tamanho long int:%ld bytes\n", sizeof(long int));

  for(long int i=0; i<NTHREADS; i++) {
    printf("--Cria a thread %ld\n", i);
    if (pthread_create(&tid_sistema[i], NULL, PrintHello, (void*) i)) {
      printf("--ERRO: pthread_create()\n"); exit(-1);
    }
  }

  printf("--Thread principal terminou\n");
  pthread_exit(NULL);
}
