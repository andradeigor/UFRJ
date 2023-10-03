#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>

#define N 3 // numero de elementos no meu buffer
#define tamLinha 1000
// Variaveis globais
sem_t slotCheio, slotVazio; // semaforos para sincronizacao por condicao
sem_t mutexGeral;           // semaforo geral de sincronizacao por exclusao mutua

// buffer
char Buffer[N][tamLinha];

// variavel de espera
int nitems = 0;

void printaBuffer()
{
    printf("Buffer: ");
    for (int i = 0; i < N; i++)
    {
        printf("%s ", Buffer[i]);
    }
    printf("\n");
}

void Retira(long int id)
{
    char aux[tamLinha];
    static int linhaRetirar = 0;
    sem_wait(&slotCheio);
    sem_wait(&mutexGeral);
    strcpy(aux, Buffer[linhaRetirar]); // pega o valor do buffer e coloca numa variável auxiliar.
    Buffer[linhaRetirar][0] = '\0';    // reseta a posição do buffer, colocando um string "vazia".
    linhaRetirar = (linhaRetirar + 1) % N;
    printf("Cons[%ld]: Consumiu: %s\n", id, aux);
    nitems--;
    sem_post(&mutexGeral);
    sem_post(&slotVazio);
}

void *consumidora(void *arg)
{
    long int id = (long int)arg;
    printf("A thread %ld foi criada\n", id);
    while (1)
    {
        Retira(id);
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
    // aloca espaco de memoria para o vetor de identificadores de threads no sistema
    tid = malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL)
    {
        printf("--ERRO: malloc()\n");
        return 2;
    }

    for (long int i = 0; i < nthreads; i++)
    {
        if (pthread_create(&tid[i], NULL, consumidora, (void *)(i + 1)))
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
        // carrega a proxima linha no Buffer e verifica se chegou ao final do arquivo.
        if (fgets(Buffer[linha], sizeof(char) * tamLinha, arquivo) == NULL)
        {
            // sai do loop se estiver no final e libera o ponteiro de lock, mas não sinaliza um slot cheio pois chegou ao fim.
            fimDoLoop = 1;
            sem_post(&mutexGeral);
            continue;
        }
        nitems++;
        for (int i = 0; i < tamLinha; i++)
        {
            // Retira o pular linha e substitui com um "fim de string"
            if (Buffer[linha][i] == '\n')
            {
                Buffer[linha][i] = '\0';
                break;
            }
        }
        printf("Prod: inseriu %s\n", Buffer[linha]);
        linha = (linha + 1) % N;
        sem_post(&mutexGeral);
        sem_post(&slotCheio);
    }
    // esperando o consumidor acabar.
    sem_wait(&slotVazio);
    while (nitems != 0)
    {
    }
    sem_destroy(&slotCheio);
    sem_destroy(&slotVazio);
    sem_destroy(&mutexGeral);
    fclose(arquivo);
    free(tid);
    free(nomeArquivo);
    return 0;
}
