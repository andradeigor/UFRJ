#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 8 // total de threads a serem criadas
#define SIZE 10000 // total de items dentro da array
// cria a estrutura de dados para armazenar os argumentos da thread
typedef struct
{
  int inicio, fim, *numeros;
} t_Args;

int VerificaResultado(int numeros[], int verificador[])
{
  for (int i = 0; i < SIZE; i++)
  {
    if (numeros[i] != verificador[i])
    {
      printf("Encontrei um problema com o número na posição %d, ele deveria ser %d, mas é %d.\n", i, verificador[i], numeros[i]);
      return 1;
    }
  }
  return 0;
}

void *ElevaAoQuadrado(void *arg)
{
  t_Args args = *(t_Args *)arg;
  for (int i = args.inicio; i < args.fim; i++)
  {
    *(args.numeros + i) = *(args.numeros + i) * *(args.numeros + i);
  }

  free(arg);

  pthread_exit(NULL);
}

int main()
{
  pthread_t tid_sistema[NTHREADS];
  t_Args *args;
  int *numeros, *verificador, gap = SIZE / NTHREADS;
  numeros = malloc(sizeof(int) * SIZE);
  verificador = malloc(sizeof(int) * SIZE);
  if (numeros == NULL || verificador == NULL)
  {
    printf("--ERRO: malloc()\n");
    exit(-1);
  }
  for (int i = 0; i < SIZE; i++)
  {
    numeros[i] = i;
    verificador[i] = i * i;
  }
  for (int i = 0; i < NTHREADS; i++)
  {
    args = malloc(sizeof(t_Args));
    if (args == NULL)
    {
      printf("--ERRO: malloc()\n");
      exit(-1);
    }
    args->inicio = i * gap;
    args->fim = i + 1 == NTHREADS ? SIZE : (i + 1) * gap;
    args->numeros = numeros;

    printf("Criando a thread %d, ela vai cuidar de [%4d-%5d[\n", i, i * gap, (i + 1) * gap);
    if (pthread_create(&tid_sistema[i], NULL, ElevaAoQuadrado, (void *)args))
    {
      printf("--ERRO: pthread_create()\n");
      exit(-1);
    }
  }

  for (int i = 0; i < NTHREADS; i++)
  {
    if (pthread_join(tid_sistema[i], NULL))
    {
      printf("--ERRO: pthread_join() \n");
      exit(-1);
    }
  }
  VerificaResultado(numeros, verificador);
  free(numeros);
  free(verificador);
  printf("--Thread principal terminou\n");
  pthread_exit(NULL);
}
