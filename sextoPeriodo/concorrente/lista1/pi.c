#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10000
#define M 8

typedef struct
{
    int inicio, fim;
    double *n;
} t_Args;

double piSequencial(long long n)
{
    double soma = 0.0, fator = 1.0;
    long long i;
    for (i = 0; i < n; i++)
    {
        soma = soma + fator / (2 * i + 1);
        fator = -fator;
    }
    return 4.0 * soma;
}

void *PiConcorrente(void *arg)
{
    t_Args args = *(t_Args *)arg;
    double fator = 1.0;
    if (!(args.inicio % 2 == 0))
    {
        fator = -fator;
    }
    for (long long i = args.inicio; i < args.fim; i++)
    {
        *(args.n) += fator / (2 * i + 1);
        fator = -fator;
    }
    free(arg);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t tid_sistema[M];
    int gap;
    double n;
    t_Args *args;
    gap = N / M;
    for (int i = 0; i < M; i++)
    {
        args = malloc(sizeof(t_Args));
        if (args == NULL)
        {
            printf("--ERRO: malloc()\n");
            exit(-1);
        }
        args->inicio = i * gap;
        args->fim = (i + 1) == M ? N : (i + 1) * gap;
        args->n = &n;
        printf("Criando a thread %d, ela vai cuidar de [%4d-%5d[\n", i, i * gap, (i + 1) * gap);
        if (pthread_create(&tid_sistema[i], NULL, PiConcorrente, (void *)args))
        {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }
    for (int i = 0; i < M; i++)
    {
        if (pthread_join(tid_sistema[i], NULL))
        {
            printf("--ERRO: pthread_join() \n");
            exit(-1);
        }
    }
    n *= 4;

    printf("o valor de pi com n=%d é de %f\n", N, n);
    return 0;
}
