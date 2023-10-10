#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define m 5 // n de threads
pthread_mutex_t mutex;
long long n = 1000000;
float result[m];
void *tarefa(void *arg)
{
    long int i = (long int)arg;
    int inicio = i * (n / m), fim = (i + 1) * (n / m), k;
    float sum = 0, fator = inicio % 2 == 0 ? 1 : -1;
    if (i == m - 1)
    {
        fim = n;
    }

    for (k = inicio; k < fim; k++)
    {
        sum += (fator / (2 * k + 1));
        fator = -fator;
    }

    result[i] = sum;
    pthread_exit(NULL);
}

int main()
{
    pthread_t *tid;

    tid = (pthread_t *)malloc(sizeof(pthread_t) * m);
    if (tid == NULL)
    {
        return 1;
    }
    float pi = 0;
    pthread_mutex_init(&mutex, NULL);
    for (long int i = 0; i < m; i++)
    {
        pthread_create((tid + i), NULL, tarefa, (void *)i);
    }

    for (int k = 0; k < m; k++)
    {
        if (pthread_join(*(tid + k), NULL))
            ;
    }
    for (int k = 0; k < m; k++)
    {
        pi += result[k];
    }
    printf("%f\n", 4 * pi);
    return 0;
}
