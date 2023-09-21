#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// variavel de lock para exclusao mutua e bloqueio.
pthread_mutex_t mutex; 
pthread_cond_t cond_leitura;
pthread_cond_t cond_escrita;
//variaveis globais para leitura e escrita.
int lendo = 0;
int possoLer = 1;
int escrevendo = 0;


void Ler(){
    pthread_mutex_lock(&mutex);
    //Enquanto alguém estiver escrevendo, ou eu não poder ler, eu fico na fila.
    while(escrevendo>0 || possoLer==0){
        pthread_cond_wait(&cond_leitura, &mutex);
    }
    lendo++;
    pthread_mutex_unlock(&mutex);
}

void SaiLeitura(){
    pthread_mutex_lock(&mutex);
    lendo--;
    //Se ngm estiver lendo, a escrita é liberada.
    if(lendo==0) pthread_cond_signal(&cond_escrita);
    pthread_mutex_unlock(&mutex);
}

void Escrita(){
    pthread_mutex_lock(&mutex);
    //Se alguém estiver lendo, ou escrevendo, eu espero travando novos leitores.
    while ((escrevendo>0)|| (lendo>0)){
        possoLer =0;
        pthread_cond_wait(&cond_escrita, &mutex);
    }
    escrevendo++;
    pthread_mutex_unlock(&mutex);
}

void SaiEscrita(){
    pthread_mutex_lock(&mutex);
    //Ao sair, eu libero novos leitores.
    escrevendo--;
    possoLer= 1;
    pthread_cond_signal(&cond_escrita);
    pthread_cond_broadcast(&cond_leitura);
    pthread_mutex_unlock(&mutex);
}


void Iniciar(){
    //inicializando os bloqueios.
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_leitura, NULL);
    pthread_cond_init(&cond_escrita, NULL);
}

void Sair(){
    //Liberando os bloqueios
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_leitura);
    pthread_cond_destroy(&cond_escrita);
}
