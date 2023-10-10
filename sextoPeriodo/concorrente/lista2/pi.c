#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#define M 5

int nthreads = 2; // numero de threads
pthread_mutex_t mutex;
float pi = 0;
int i_global = 0;
void *calc_pi(void *arg)
{
    long int n = (long int)arg;
    int i;
    pthread_mutex_lock(&mutex);
    i = i_global;
    i_global++;
    pthread_mutex_unlock(&mutex);

    while (i < n)
    {
        pi += ((4.0 / (8 * i + 1)) - (2.0 / (8 * i + 4)) - (1.0 / (8 * i + 5)) - (1.0 / (8 * i + 6))) * (1 / pow(16, i));
        pthread_mutex_lock(&mutex);
        i = i_global;
        i_global++;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t *tid;
    pthread_mutex_init(&mutex, NULL);
    long int n = 100;
    tid = (pthread_t *)malloc(sizeof(tid) * M);
    for (int i = 0; i < M; i++)
    {
        pthread_create((tid + i), NULL, calc_pi, (void *)n);
    }

    for (int i = 0; i < M; i++)
    {
        if (pthread_join(*(tid + i), NULL))
            ;
    }

    printf("o numeo pi com %ld como parâmetro é %f\n", n, pi);
    return 0;
}
