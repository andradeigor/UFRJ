#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

#define N 100 // numero de elementos no meu buffer
#define tamLinha 10000
// Variaveis globais
sem_t slotCheio, slotVazio; // semaforos para sincronizacao por condicao
sem_t mutexGeral;           // semaforo geral de sincronizacao por exclusao mutua

// buffer
char Buffer[N][tamLinha];

void Retira()
{
    char aux[tamLinha];
    static int linhaRetirar = 0;
    sem_wait(&slotCheio);
    sem_wait(&mutexGeral);
    strcpy(aux, Buffer[linhaRetirar]);
    Buffer[linhaRetirar][0] = '\0';
    linhaRetirar = (linhaRetirar + 1) % N;
    printf("Cons[]: retirou %s\n", aux);
    sem_post(&mutexGeral);
    sem_post(&slotVazio);
}

void *consumidora(void *arg)
{
    while (1)
    {
        Retira();
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    int nthreads, linha = 0, fimDoLoop = 0;
    pthread_t *tid;
    FILE *arquivo;
    char *nomeArquivo;
    // Iniciando os semaforos
    sem_init(&mutexGeral, 0, 1);
    sem_init(&slotCheio, 0, 0);
    sem_init(&slotVazio, 0, N);

    // verifica se o numero de threads e o nome do arquivo foi passado na linha de comando
    if (argc < 3)
    {
        printf("Digite: %s <numero de threads> <nome do arquivo de texto>\n", argv[0]);
        return 1;
    }
    nthreads = atoi(argv[1]);
    // reserva o tamanho para o nome do arquivo
    nomeArquivo = malloc(strlen(argv[2]) + 1);

    if (nomeArquivo == NULL)
    {
        printf("--ERRO: malloc()\n");
        return 1;
    }
    // copia o nome do arquivo para a variável
    strcpy(nomeArquivo, argv[2]);
    printf("%s\n", nomeArquivo);
    // aloca espaco de memoria para o vetor de identificadores de threads no sistema
    tid = malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL)
    {
        printf("--ERRO: malloc()\n");
        return 2;
    }

    for (long int i = 0; i < nthreads; i++)
    {
        if (pthread_create(&tid[i], NULL, consumidora, (void *)i))
        {
            printf("Erro na criacao do thread consumidora\n");
            exit(1);
        }
    }

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("--ERRO: arquivo\n");
        return 2;
    }
    while (fimDoLoop == 0)
    {
        sem_wait(&slotVazio);
        sem_wait(&mutexGeral);
        if (fgets(Buffer[linha], sizeof(char) * tamLinha, arquivo) == NULL)
        {
            fimDoLoop = 1;
            continue;
        }
        printf("Prod: inseriu %s", Buffer[linha]);
        linha = (linha + 1) % N;
        sem_post(&mutexGeral);
        sem_post(&slotCheio);
    }
    int i = 0;
    while (i < 3)
    {
        for (int k = 0; k < linha; k++)
        {
            puts(Buffer[k]);
        }
        sleep(1);
    }
    fclose(arquivo);
    free(tid);
    free(nomeArquivo);
    return 0;
}
