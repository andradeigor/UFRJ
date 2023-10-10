### Questão 1)

```c
sem_t mutex; //exclusao mutua (iniciado com 1)
sem_t cond; //condicional (iniciado com 0)
 int chegaram=0; //variavel de estado global
 void barreira(int numThreads) {
    sem_wait(&mutex);
    chegaram++;
    if (chegaram < numThreads) {
        sem_post(&mutex);
        sem_wait(&cond);
    chegaram--;
    if(chegaram ==0){
        sem_post(&mutex);
    }else{
        sem_post(&cond);
    }
}


```

    (a)O problema dessa implementação está no fato de que ao se liberar as threads por meio do post no for, são acumulados sinais de liberação internamente, e pode ocorrer de que uma thread que foi liberada ganhe tempo de cpu e chegue novamente na barreira, pegue o mutex que a ultima thread liberou, entre no if de espera e pegue o sinal de &cond antes que uma das threads que deveriam ser liberadas pelo post pegue, fazendo com que ela fure a barreira. O erro está nesse acumulo de post para a liberação

    (b)

```c
sem_t mutex; //exclusao mutua (iniciado com 1)
sem_t cond; //condicional (iniciado com 0)
 int chegaram=0; //variavel de estado global
 void barreira(int numThreads) {
    sem_wait(&mutex);
    chegaram++;
    if (chegaram < numThreads) {
        sem_post(&mutex);
        sem_wait(&cond);
    chegaram--;
    if(chegaram ==0){
        sem_post(&mutex);
    }else{
        sem_post(&cond);
    }
}
```

### Questão 2)

```c
 int leitores=0; //leitores lendo
 sem_t mutex, escrita; //inicializados com 1 sinal cada

 void leitor(){
    sem_wait(&mutex);
    leitores++;
    if(leitores==1) //primeiro leitor
    {
         sem_wait(&escrita);
    }
    sem_post(&mutex);
    /* faz a leitura .... */
    sem_wait(&mutex);
    leitores--;
    if(leitores==0) //ultimo leitor
    {
        sem_post(&escrita);
    }
    sem_post(&mutex);
}

 void escritor(){
    sem_wait(&escrita);
    /* faz a escrita .... */
    sem_post(&escrita);
 }

```

Sim, ela atende todas as necessidades de um padrão leitor e escritor. Quando se inicia o código, escrita está com sinal 1, e dependendo do fluxo ou um leitor ou um escritor irá pegar esse sinal. Caso um escritor pegue, o sinal ficará com 0 e nenhum outro escritor ou leitor conseguirá pegar. Esse sinal só irá ser acrescentado novamente no final da escrita, permitindo assim um novo escritor(a lógica aqui se repete nesse caso), ou um leitor pegar. No fluxo de leitores, o início dele é pegar o sinal do mutex, bloqueando outros leitores de pegarem(nesse momento). Após isso, ele incrementa o número de leitores e vê se ele é o primeiro, caso seja, espera o sinal dos escritores que foi dito anteriormente. Caso ele consiga pegar o sinal, nenhum escritor conseguirá pegar pela lógica explicada anteriormente, e o fluxo fica livre para os leitores. Após isso, ele libera o mutex e permite outros leitores de entratrem, quando ele termina a leitura, ele pega o mutex e diminui o valor de leitores, confere se é o último leitor, caso seja ele libera um escritor, caso contrário ele só libera o mutex.

### Questão 3)

```c
#define N 5 //tamanho do buffer
int Buffer[N], size=0; //buffer e contador
pthread_mutex_t mutex;
pthread_cond_t condProd,condConsu;
//variáveis de mutex e cond foram devidamente inicializadas.
void insere(int item){
    static int in=0;
    pthread_mutex_lock(&mutex);
    while(size ==N){
        pthread_cond_wait(&condProd, &mutex);
    }
    Buffer[in] = item;
    in = (in+1)%N;
    size++;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&condConsu);

}

void retira(void){
    static int out=0;
    int elem;
    thread_mutex_lock(&mutex);
    while(size ==0){
        pthread_cond_wait(&condConsu, &mutex);
    }
    elem = Buffer[out];
    out = (out+1)%;
    size--;
    thread_mutex_unlock(&mutex);
    pthread_cond_signal(&condProd, &mutex);
    return elem;
}



```

### Questão 4)

```c

#define N 5;
int Buffer[N], size=0;
sem_t slotVazio, slotCheio, mutex;
//variáveis de semáforo foram devidamente iniciadas. Mutex com 1, slotVazio com N e slotCheio com 0.

void insere(int item){
    static int in=0;
    sem_wait(&slotVazio);
    sem_wait(&mutex;);
    size++;
    Buffer[in] = item;
    in = (in+1)%N;
    if(size == N){
        size=0;
        sem_post(&slotCheio);
    }
    sem_post(&mutex);
}

void retira(void){
    int Item;
    sem_wait(&slotCheio);
    for(int i=0;i<N;i++){
        item = Buffer[i];
        sem_post(&slotVazio);//como não liberei o mutex, nenhum produtor vai inserir.
    }
}
```

### Questão 5)

```c
//globais
int a=0, b=0; //numero de threads foo e bar usando o recurso, respectivamente
sem_t emA, emB; //semaforos para exclusao mutua
sem_t rec; //semaforo para sincronizacao logica
//inicializacoes que devem ser feitas na main() antes da criacao das threads
sem_init(&emA, 0, 1);
sem_init(&emB, 0, 1);
sem_init(&rec, 0, 1);

void *foo () {
    while(1) {
        sem_wait(&emA);
        a++;
        if(a==1) {
            sem_wait(&rec);
        }
        sem_post(&emA);
        //SC: usa o recurso
        sem_wait(&emA);
        a--;
        if(a==0) sem_post(&rec);
        sem_post(&emA);
    }
}
void *bar () {
    while(1) {
        sem_wait(&emB);
        b++;
        if(b==1) {
            sem_wait(&rec);
        }
        sem_post(&emB);
        //SC: usa o recurso
        sem_wait(&emB);
        b--;
        if(b==0) sem_post(&rec);
        sem_post(&emB);
    }
}
```

Essa questão funciona parecido com o padrão leitor escritor, mas de forma diferente. Normalmente, nós podemos ter vários leitores mas só um escritor. Aqui, temos o funcionamento diferente, podemos ter vários foo ao mesmo tempo, e podemos ter vários bar ao mesmo tempo. Mas, não podemos ter foo e bar ao mesmo tempo. Contanto que um deles esteja sendo executado, podemos ter vários do mesmo tipo, mas nunca dois tipos ao mesmo tempo.

### Questão 6)

```c
sem_t em_e, em_l, escr, leit; //semaforos iniciados com 1 sinal
int e=0, l=0;
void AntesLeitura() {
    sem_wait(&leit);
    sem_wait(&em_l);
    l++;
    if(l==1) sem_wait(&escr);
    sem_post(&em_l);
    sem_post(&leit);
}
void DepoisLeitura() {
    sem_wait(&em_l);
    l--;
    if(l==0) sem_post(&escr);
    sem_post(&em_l);
}
void AntesEscrita() {
    sem_wait(&em_e);
    e++;
    if(e==1) sem_wait(&leit);
    sem_post(&em_e);
    sem_wait(&escr);
}
void DepoisEscrita() {
    sem_post(&escr);
    sem_wait(&em_e);
    e--;
    if(e==0) sem_post(&leit);
    sem_post(&em_e);
}
```
