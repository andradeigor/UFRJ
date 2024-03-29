#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

long int aux = 0;
int nthreads;          // numero de threads
pthread_mutex_t mutex; // variavel de lock para exclusao mutua
pthread_cond_t cond;
char textos[3][30] = {"Olá da thread ", "Que dia bonito ", "Até breve da thread "};

void *tarefa(void *id)
{
    int my_id = (long int)id + 1;
    // rodo esse for 3 vezes para representar cada uma das barreiras.
    for (int i = 0; i < 3; i++)
    {
        pthread_mutex_lock(&mutex);
        // textos[i] é o texto que vai ser impresso pela thread guardado no vetor "textos".
        printf("%s", textos[i]);
        // Aqui, printo o digito de id da thread e pulo linha, esses 2 prints saem juntos como se fossem um só.
        printf("%d \n", my_id);
        aux++;
        // essa variável aux serve para verificar se todas a threads já chegaram na barreira, vejo isso pelo resto da divisão delas pelo numero de threads.
        if (aux % nthreads != 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        else
        {
            pthread_cond_broadcast(&cond);
            // pulo uma linha para ficar igual o print do enunciado.
            printf("\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t *tid; // identificadores das threads no sistema
    if (argc < 2)
    {
        printf("Digite: %s <numero de threads>\n", argv[0]);
        return 1;
    }
    nthreads = atoi(argv[1]);
    tid = (pthread_t *)malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL)
    {
        puts("ERRO--malloc");
        return 2;
    }
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (long int i = 0; i < nthreads; i++)
    {

        if (pthread_create(tid + i, NULL, tarefa, (void *)i))
        {
            puts("ERRO--pthread_create");
            return 3;
        }
    }
    // espera pelo termino da threads
    for (int i = 0; i < nthreads; i++)
    {
        pthread_join(*(tid + i), NULL);
    }
    // liberacao da memoria

    free(tid);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
