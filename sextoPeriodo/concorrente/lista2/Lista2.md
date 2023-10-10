### Questão 1)

No programa de multiplicação de matrizes mostramos (Cap 2 - texto) uma forma de paralelizar o algoritmo de multiplicação de matrizes criando um fluxo de execução independente para calcular cada um dos elementos da matriz de saída. Proponha outra solução onde a tarefa de cada fluxo de execução seja calcular uma linha inteira da matriz de saída.

### Resposta:

Dentro do código disponibilizado, temos dois for dentro da main que fazem a varredura das células da matriz resultado, sendo no qual o i varre as linhas e o j as colunas. Como queremos que o nosso código calcule paralelamente uma linha inteira, precisamos que, no final, a função de calcular percorra todos os j da linha i que foi passada para ela calcular. Fazemos isso colocando o for do j dentro da função "calculaElementoMatriz", agora toda chamada da função percorre toda a linha i que foi passada.

```c
#define N 1000 //N igual à dimensão da matriz
float a[N][N], b[N][N], c[N][N];
void calculaElementoMatriz(int dim, int i, int j) {
    int k, soma;
    for(j=0; j< dim; j++) {
        soma = 0.0
        for(k=0; k<dim; k++) {
            soma = soma + a[i][k] * b[k][j];
    }
    c[i][j] = soma;
    }
}
void main() {
    int i, j;
    //inicializa as matrizes a e b (...)
    //faz C = A * B
    for(i=0; i<N; i++) {
    //dispara um fluxo de execução f para executar:
        calculaElementoMatriz(N, i, j);
    }
}
```

### Questão 2)

Para arquiteturas de hardware com poucas unidades de processamento (como é o caso das CPUs multicores) geralmente é melhor criar uma quantidade de fluxos de execução igual ao número de unidades de processamento. Altere a solução do exercício anterior fixando o numero de fluxos de execução e dividindo o cálculo das linhas da matriz de saída entre eles.

### Resposta)

Aqui preciamos dar mais um "passo" na paralelização, até parecido com a anterior. Isso porque, nós basicamente colocamos várias linhas dentro de uma mesma chamada. Isso foi feito criando uma constante NCPU que guarda o número de unidades de processamento que o computador tem. Com base nele, dividimos o número de linhas da matriz e temos uma fatia igual para cada um dessas unidades calculas. Por fim, um detalhe que foi implementado foi que a ultima fatia de processamento necessariamente vai necessáriamente até o final da matriz, isso é feito para garantir que a função rode na matriz inteira mesmo nos casos de que a divisão de N/NCPU não seja inteira.

```c
#define N 1000 //N igual à dimensão da matriz
#define NCPU 8 // Número de exemplo.
float a[N][N], b[N][N], c[N][N];
void calculaElementoMatriz(int dim, int inicio, int j, int fim) {
    int k, soma;
    for(i=inicio; i<fim; i++){
        for(j=0; j< dim; j++) {
            soma = 0.0
            for(k=0; k<dim; k++) {
                soma = soma + a[i][k] * b[k][j];
        }
        c[i][j] = soma;
        }
    }
}
void main() {
    int i, j, gap,fim;
    //inicializa as matrizes a e b (...)
    //faz C = A * B
    gap = N/NCPU;
    for(i=0; i<NCPU; i++) {
        fim= i+1 == NCPU? N : (i+1) * gap;
        //dispara um fluxo de execução f para executar:
        calculaElementoMatriz(N, i*gap, j,fim );
    }
}
```

### Questão 3)

A serie mostrada abaixo pode ser usada para estimar o valor da constante π. A funcção piSequencial() implementa o calculo dessa série de forma sequencial.Proponha um algoritmo concorrente para resolver esse problema dividindo a tarefa de estimar o valor de π entre M fluxos de execução independentes.

### Resposta)

Fiquei em dúvida com relação ao como eu deveria fazer esse implementação, se eu deveria fazer só a parte da função considerando que os dados me seriam passado, ou deveria fazer por completo. Na dúvida, fiz por completo. Segui o mesmo principio das anteriores, passo um inicio e um fim para a função que faz o calculo, junto com um ponteiro para a variável que guarda o valor da soma:

```c
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
```

o unico detalhe que precisei ficar de olho era verificar se o inicio era par ou impar para poder mudar o sinal inicial.

Na main nada de muito especial foi feito:

```c
#define N 10000
#define M 8

typedef struct
{
    int inicio, fim;
    double *n;
} t_Args;

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
```

Foi feito com base no código disponibilizado pela professora do lab1, apenas mudando para o problema de pi. A saída foi:

```bash
Criando a thread 0, ela vai cuidar de [   0- 1250[
Criando a thread 1, ela vai cuidar de [1250- 2500[
Criando a thread 2, ela vai cuidar de [2500- 3750[
Criando a thread 3, ela vai cuidar de [3750- 5000[
Criando a thread 4, ela vai cuidar de [5000- 6250[
Criando a thread 5, ela vai cuidar de [6250- 7500[
Criando a thread 6, ela vai cuidar de [7500- 8750[
Criando a thread 7, ela vai cuidar de [8750-10000[
o valor de pi com n=10000 é de 3.141482

```

### Questão 4)

1. Complete a coluna A com os valores de aceleração.

### Resposta)

| N        | threads | Ts(s) | Tc(s) | A    |
| -------- | ------- | ----- | ----- | ---- |
| 1 × 10^6 | 1       | 0,88  | 0,89  | 0.98 |
| 1 × 10^6 | 2       | 0,88  | 0,50  | 1.76 |
| 1 × 10^7 | 1       | 8,11  | 8,34  | 0.97 |
| 1 × 10^7 | 2       | 8,11  | 4,44  | 1.82 |
| 2 × 10^7 | 1       | 16,21 | 16,41 | 0.98 |
| 2 × 10^7 | 2       | 16,21 | 8,84  | 1.83 |

2. Avalie os resultados obtidos para essa metrica. Considere os casos em que a carga de dados aumenta junto com o numero de processadores e os casos isolados onde apenas a carga de trabalho ou o numero de processadores aumenta.

### Resposta)

Segundo o capitulo 2 do lívro, quando paralelizamos um programa, o ideal seria conseguir uma aceleração que seria igual ao numero de threads usada. Porém, vemos que isso não é o caso em nenhum deles. Podemos analisar também, olhando só para o comportamento sequêncial que o aumento de tempo é praticamente linear com o aumento do tamanho da entrada. Entretanto, essa diminuição no tempo não acompanha o número de threads linearmente, temos aqui um caso sublinear, na qual o aumento na velocidade de execução não é exatamente o tempo sequêncial dividido pelo número de threads.

### Questão 5)

Considere uma aplicação na qual 20% do tempo total de execução e comprometido com tarefas sequenciais e o restante, 80%, pode ser executado de forma concorrente.

1. Se dispusermos de uma maquina com 4 processadores, qual sera a aceleração teorica (de acordo com a lei de Amdahl) que poderá ser alcançada em uma versão concorrente da aplicação?

### Reposta)

At = 1/(1-0.8)+(0.8/4) = 2.5
Assim, conseguiremos uma acelecação teórica de 2.5x

2. Se apenas 50% das atividades pudessem ser executadas em paralelo, qual seria a aceleracão teórica considerando novamente uma máquina com 4 processadores?

At = 1/(1-0.5)+(0.5/4) = 1.6
Assim, conseguiremos uma acelecação teórica de 1.6x
