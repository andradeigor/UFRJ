/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Codigo: Comunicação entre threads usando variável compartilhada */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define NTHREADS  2

int soma = 0; //variavel compartilhada entre as threads

//funcao executada pelas threads
void *ExecutaTarefa (void *arg) {
  long int id = (long int) arg;
  printf("Thread : %ld esta executando...\n", id);

  for (int i=0; i<100000; i++) {
     soma++; //incrementa a variavel compartilhada 
  }
  printf("Thread : %ld terminou!\n", id);
  pthread_exit(NULL);
}

//fluxo principal
int main(int argc, char *argv[]) {
  pthread_t tid[NTHREADS];

  //--cria as threads
  for(long int t=0; t<NTHREADS; t++) {
    if (pthread_create(&tid[t], NULL, ExecutaTarefa, (void *)t)) {
      printf("--ERRO: pthread_create()\n"); exit(-1);
    }
  }

  //--espera todas as threads terminarem
  for (int t=0; t<NTHREADS; t++) {
    if (pthread_join(tid[t], NULL)) {
         printf("--ERRO: pthread_join() \n"); exit(-1); 
    } 
  } 

  printf("Valor de 'soma' = %d\n", soma);

  return 0;
}
