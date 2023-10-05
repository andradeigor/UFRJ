#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>

#define N 3 // numero de elementos no meu buffer
#define tamLinha 1000 // Tamanho máximo da linha
// Variaveis globais
sem_t slotCheio, slotVazio; // semaforos para sincronizacao por condicao
sem_t mutexGeral;           // semaforo geral de sincronizacao por exclusao mutua

// buffer
char Buffer[N][tamLinha];

// variavel de espera
int nitems = 0;

void Insere(char *linha){
    static int linhaColocar = 0;
    sem_wait(&slotVazio);
    sem_wait(&mutexGeral);
    // carrega a proxima linha no Buffer
    strcpy(Buffer[linhaColocar], linha);
    nitems++;
    printf("Prod: inseriu %s\n", Buffer[linhaColocar]);
    //avança para a proxima linha
    linhaColocar = (linhaColocar + 1) % N;
    sem_post(&mutexGeral);
    sem_post(&slotCheio);

}

void Retira(long int id)
{
    char aux[tamLinha];
    static int linhaRetirar = 0;
    sem_wait(&slotCheio);
    sem_wait(&mutexGeral);
    strcpy(aux, Buffer[linhaRetirar]); // pega o valor do buffer e coloca numa variável auxiliar.
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
    int nthreads;
    pthread_t *tid;
    FILE *arquivo;
    char linhaAuxiliar[tamLinha];
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

    // Tentar abrir o arquivo, caso não consiga já encerra.
    arquivo = fopen(argv[2], "r");
    if (arquivo == NULL)
    {
        printf("--ERRO: ao ler o arquivo\n");
        return 2;
    }
    // aloca espaco de memoria para o vetor de identificadores de threads no sistema.
    tid = malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL)
    {
        printf("--ERRO: malloc()\n");
        return 2;
    }
    //cria as n threads, passando um id para cada uma.
    for (long int i = 0; i < nthreads; i++)
    {
        if (pthread_create(&tid[i], NULL, consumidora, (void *)(i + 1)))
        {
            printf("Erro na criacao do thread consumidora\n");
            exit(1);
        }
    }
    //Enquanto tivermos uma linha no arquivo, lemos a linha.
    while (fgets(linhaAuxiliar, sizeof(char) * tamLinha, arquivo) != NULL)
    {
        for (int i = 0; i < tamLinha; i++)
        {
            // Retira o pular linha e substitui com um "fim de string"
            if (linhaAuxiliar[i] == '\n')
            {
                linhaAuxiliar[i] = '\0';
                break;
            }
        }
        //Chama a função de inserir
        Insere(linhaAuxiliar);
        
    }
    // esperando o consumidor acabar.
    while(nitems>0){
    }
    //destroindo os semáforos e liberando a memória
    sem_destroy(&slotCheio);
    sem_destroy(&slotVazio);
    sem_destroy(&mutexGeral);
    fclose(arquivo);
    free(tid);
    return 0;
}
