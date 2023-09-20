#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

long long int N;
long long int nPrimo = 0;
int nthreads;          // numero de threads
pthread_mutex_t mutex; // variavel de lock para exclusao mutua

typedef struct
{
    int id, *i;
} tArgs;

int ehPrimo(long long int n)
{
    int i;
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}
void *tarefa(void *Arg)
{
    tArgs *Args = (tArgs *)Arg;
    long int total = 0;
    // realizando o acesso separado de cada item do argumento, faço isso para distribuir igualmente o trabalho entre as threads.
    pthread_mutex_lock(&mutex);
    int i = *(Args->i);
    *(Args->i) = *(Args->i) + 1;
    pthread_mutex_unlock(&mutex);
    // enquanto eu não estiver no ultimo número, a thread vai continuar rodando o código
    while (i <= N)
    {
        if (ehPrimo(i))
        {
            total++;
        }
        // pegando o proximo item.
        pthread_mutex_lock(&mutex);
        i = *Args->i;
        *(Args->i) = *(Args->i) + 1;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit((void *)total);
}

int main(int argc, char *argv[])
{
    pthread_t *tid; // identificadores das threads no sistema
    double delta, fim, inicio;
    // decidi usar um int para guardar o numero no lugar de um vetor, não vi sentido em criar um vetor de n possíções onde o i representava também o valor do que iria acessar.
    int numero = 1;
    tArgs *Args;
    // variável que guarda o resultado retornado pela thread
    void *result;
    GET_TIME(inicio);
    if (argc < 3)
    {
        printf("Digite: %s <o valor de N> <numero de threads>\n", argv[0]);
        return 1;
    }
    N = atoll(argv[1]);
    nthreads = atoi(argv[2]);
    if (nthreads > N)
        nthreads = N;

    tid = (pthread_t *)malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL)
    {
        puts("ERRO--malloc");
        return 2;
    }
    Args = (tArgs *)malloc(sizeof(tArgs) * nthreads);
    if (Args == NULL)
    {
        puts("ERRO--malloc");
        return 2;
    }

    pthread_mutex_init(&mutex, NULL);
    GET_TIME(fim);
    delta = fim - inicio;
    printf("Tempo inicializacao:%lf\n", delta);
    GET_TIME(inicio);
    for (int i = 0; i < nthreads; i++)
    {
        Args->i = &numero;
        Args->id = i;
        if (pthread_create(tid + i, NULL, tarefa, (void *)(Args)))
        {
            puts("ERRO--pthread_create");
            return 3;
        }
    }
    // espera pelo termino da threads e somando o resultado.
    for (int i = 0; i < nthreads; i++)
    {
        pthread_join(*(tid + i), &result);
        nPrimo += (long int)result;
    }
    GET_TIME(fim)
    delta = fim - inicio;
    printf("Tempo de procurar Primos %lf\n", delta);

    // liberacao da memoria
    GET_TIME(inicio);
    free(Args);
    free(tid);
    pthread_mutex_destroy(&mutex);
    GET_TIME(fim)
    delta = fim - inicio;
    printf("Tempo finalizacao:%lf\n", delta);
    printf("Número de primos:%lld\n", nPrimo);

    return 0;
}