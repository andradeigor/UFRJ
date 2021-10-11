## Lista 8

###  Nome: Igor de Andrade Assunção de Almeida


### DRE:121095736



### Questão 1:

O código foi executado, o resultado foi a impressão dos dados lidos como esperado

"""

Entre com as coordenadas do ponto p 

5 2

 Dados lidos

  Ponto p:x = 5.000000 , y=  2.000000 

"""

### Questão 2:

O código foi executado, o resultado foi a impressão dos dados lidos como esperado:

"""

Entre com o raio do circulo c1 

 5

Entre com as coordenadas do centro do circulo 1

 1 3

 Dados lidos

  Circulo c1 : raio = 5.000000 , x = 1.000000 , y =  3.000000 

"""

Questão 3:
```
#include <stdio.h>
#include <math.h>
typedef struct {
    float x,y;
}COORD;

float distancia(float x1, float y1, float x2, float y2  ){
    float dist;
    dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return dist;
}


int main(){
    COORD coord1,coord2;
    printf("Por favor, digite a primeira coordenada x,y (ex:1,1): ");
    scanf("%f,%f", &coord1.x,&coord1.y);
    while(getchar()!='\n');
    printf("Por favor, digite a segunda coordenada x,y (ex:1,1): ");
    scanf("%f,%f", &coord2.x,&coord2.y);
    while(getchar()!='\n');
    printf("A distância entre %1.1f,%1.1f e %1.1f,%1.1f é %1.2f\n", coord1.x,coord1.y,coord2.x,coord2.y, distancia(coord1.x,coord1.y,coord2.x,coord2.y));

    return 0;
}
```

### Questão 4:
```
#include <stdio.h>
#include <math.h>

typedef struct {
    float x,y;
}COORD;
typedef struct {
    float x,y,r;
}CIRCULO;
float distancia(float x1, float y1, float x2, float y2  ){
    float dist;
    dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return dist;
}


int main(){
    COORD coord1;
    CIRCULO circ1;
    float dist;
    printf("Por favor, digite a primeira coordenada x,y (ex:1,1): ");
    scanf("%f,%f", &coord1.x,&coord1.y);
    while(getchar()!='\n');
    printf("Por favor, digite as coordenadas de origem do circulo e o raio x,y,r (ex:1,1,2): ");
    scanf("%f,%f,%f", &circ1.x,&circ1.y, &circ1.r);
    while(getchar()!='\n');
    dist = distancia(coord1.x, coord1.y, circ1.x, circ1.y);
    if(dist>circ1.r){
        printf("O ponto está fora do circulo\n");
    }else{
        printf("O ponto está dentro do circulo\n");
    }
    return 0;
}
```

### Questão 5:

```
#include <stdio.h>

typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

TEMPO maiorTempo(TEMPO t1, TEMPO t2){
    int maior;
    if (t1.hora>t2.hora){
        maior = 1;
    }else if(t1.hora<t2.hora){
        maior = 2;
    }
    else if(t1.minuto>t2.minuto){
        maior = 1;
    }else if(t1.minuto<t2.minuto){
        maior = 2;
    }else if(t1.segundo>t2.segundo){
        maior = 1;
    }else{
        maior = 2;
    }
    return maior == 1? t1:t2;
}

int main(){
    TEMPO t1, t2,t3;
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t1.hora,&t1.minuto,&t1.segundo);
    while(getchar()!='\n');
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t2.hora,&t2.minuto,&t2.segundo);
    while(getchar()!='\n');
    t3 = maiorTempo(t1,t2);
    printf("O maior tempo é %d:%d:%d\n", t3.hora,t3.minuto,t3.segundo);
    return 0;
}
```

### Questão 6:
```
#include <stdio.h>

typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

TEMPO maiorTempo(TEMPO t1, TEMPO t2){
    TEMPO t3;
    /* o compilador reclama que a variável não foi inicializada, precisei iniciar os valores como 0 mesmo sendo feio*/
    t3.hora = 0;
    t3.minuto = 0;
    t3.segundo = 0;
    if(t1.segundo+t2.segundo >= 60){
        t3.minuto += (t1.segundo+t2.segundo)/60;
        t3.segundo += (t1.segundo+t2.segundo)%60;
    }else{
        t3.segundo = t1.segundo + t2.segundo;
    }
    if(t1.minuto+t2.minuto >= 60){
        t3.hora += (t1.minuto+t2.minuto)/60;
        t3.minuto += (t1.minuto+t2.minuto)%60;
    }else{
        t3.minuto = t1.minuto + t2.minuto;
    }
    t3.hora += t1.hora + t2.hora;
    return t3;
}

int main(){
    TEMPO t1, t2,t3;
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t1.hora,&t1.minuto,&t1.segundo);
    while(getchar()!='\n');
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t2.hora,&t2.minuto,&t2.segundo);
    while(getchar()!='\n');
    t3 = maiorTempo(t1,t2);
    printf("A soma dos tempos é %d:%d:%d\n", t3.hora,t3.minuto,t3.segundo);
    return 0;
}
```

### Questão 7:
```
#include <stdio.h>

typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

int comparaTempo(TEMPO t1, TEMPO t2){
    int maior=0;
    if (t1.hora>t2.hora){
        maior = 1;
    }else if(t1.hora<t2.hora){
        maior = -1;
    }
    else if(t1.minuto>t2.minuto){
        maior = 1;
    }else if(t1.minuto<t2.minuto){
        maior = -1;
    }else if(t1.segundo>t2.segundo){
        maior = 1;
    }else if(t1.segundo<t2.segundo){
        maior = -1;
    }
    return maior;
}

int main(){
    TEMPO t1, t2;
    int maior;
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t1.hora,&t1.minuto,&t1.segundo);
    while(getchar()!='\n');
    printf("Por favor, digite o primeiro tempo hora:minuto:segundo (ex 12:50:12): ");
    scanf("%d:%d:%d", &t2.hora,&t2.minuto,&t2.segundo);
    while(getchar()!='\n');
    maior = comparaTempo(t1,t2);
    printf("A avaliação gerou: %d\n", maior);
    return 0;
}


```

### Questão 8:

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 50
typedef struct _TEMPO {
    int hora , minuto , segundo;
} TEMPO;

int comparaTempo(TEMPO t1, TEMPO t2){
    int maior=0;
    if (t1.hora>t2.hora){
        maior = 1;
    }else if(t1.hora<t2.hora){
        maior = -1;
    }
    else if(t1.minuto>t2.minuto){
        maior = 1;
    }else if(t1.minuto<t2.minuto){
        maior = -1;
    }else if(t1.segundo>t2.segundo){
        maior = 1;
    }else if(t1.segundo<t2.segundo){
        maior = -1;
    }
    return maior;
}
int merge(TEMPO *array, int comeco, int meio, int fim){
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;
    TEMPO *vetorEsquerda,*vetorDireita;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;
    vetorEsquerda = (TEMPO *) malloc (tamanhoEsquerda*sizeof( TEMPO ));
    vetorDireita = (TEMPO *) malloc (tamanhoDireita*sizeof( TEMPO )); 
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
    }
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
    }
    for(i=comeco;i<=(fim);i++){
        if(topoEsquerda >= tamanhoEsquerda){
            array[i] = vetorDireita[topoDireita];
            topoDireita ++;
        }
        else if(topoDireita >= tamanhoDireita){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else if(comparaTempo(vetorEsquerda[topoEsquerda],vetorDireita[topoDireita]) <0){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else{
            array[i] = vetorDireita[topoDireita];
            topoDireita++;
        }
    }
    free(vetorEsquerda);
    free(vetorDireita);
    return 0;
}

int mergeSort( TEMPO *array, int comeco, int fim){
    int meio;
    if(comeco<fim){
        meio = (comeco+fim)/2;
        mergeSort(array,comeco,meio);
        mergeSort(array,meio+1,fim);
        merge(array, comeco, meio, fim);
    }
    return 0;
}

int main(){
    int i;
    TEMPO *tempos;
    tempos = ( TEMPO *) malloc ( sizeof (TEMPO)*DIM);
    srand(time(NULL));
    for(i=0;i<DIM;i++){
        (tempos + i) ->hora = rand()%60;
        (tempos + i) ->minuto = rand()%60;
        (tempos + i) ->segundo = rand()%60;
    }
    mergeSort(tempos,0,DIM-1);
    for ( i = 0; i < DIM; i++)
    {
        printf("%i = %d:%d:%d\n", i,(tempos+i)->hora,(tempos+i)->minuto,(tempos+i)->segundo);
    }
    return 0;
}
```

### Questão 9:
```
#include <stdio.h>
#include <math.h>

typedef struct _PONTO{
float x,y;
}PONTO;

typedef struct _CIRCUNFERENCIA{
float raio;
PONTO centro;
}CIRCUNFERENCIA;



float distancia(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2 ){
    float dist;
    dist = sqrt(pow(c2.centro.x-c1.centro.x,2) + pow(c2.centro.y-c1.centro.y,2));
    return dist;
}
int interno(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2){
    int interno=0;
    float dist;
    dist = distancia(c1,c2);
    if(c1.raio > c2.raio ){
        if(dist + c2.raio < c1.raio){
        interno =1;
        }
    }
    if(c2.raio > c1.raio ){
        if(dist + c1.raio < c2.raio){
        interno =1;
        }
    }
 
    return interno;
}

int externas(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2){
    int externo=0;
    float dist;
    dist = distancia(c1,c2);
    if(dist > c1.raio+c2.raio){
        externo =1;
    }
    return externo;
}
int tangente(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2){
    int tangente=0;
    float dist;
    dist = distancia(c1,c2);
    if(dist == c1.raio+c2.raio){
        tangente =1;
    }
    return tangente;
}
int secante(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2){
    int secante=0;
    float dist;
    dist = distancia(c1,c2);
    if(dist < c1.raio+c2.raio && dist > fabs(c1.raio - c2.raio)){
        secante =1;
    }
    return secante;
}

int main(){
    CIRCUNFERENCIA c1, c2;
    int isSec,isInter,isTan,isExt;
    printf( "Entre com o raio do circulo c1: " );
    scanf( "%f" , &c1.raio );
    printf ( "Entre com as coordenadas do centro do circulo 1: " );
    scanf( "%f %f" , &c1.centro.x , &c1.centro.y );
    printf( "Dados lidos\n" );
    printf( "Entre com o raio do circulo c2: " );
    scanf( "%f" , &c2.raio );
    printf ( "Entre com as coordenadas do centro do circulo 2: " );
    scanf( "%f %f" , &c2.centro.x , &c2.centro.y );
    printf( "Dados lidos\n" );
    printf("c1 raio: %1.2f x=%1.2f, y=%1.2f\nc2 raio: %1.2f x=%1.2f, y=%1.2f\n", c1.raio, c1.centro.x, c1.centro.y,c2.raio,c2.centro.x,c2.centro.y);
    isInter = interno(c1,c2);
    isTan = tangente(c1,c2);
    isSec = secante(c1,c2);
    isExt = externas(c1,c2);
    if(isInter){
        printf("As circunferências são internas!!!\n");
    }else{
        printf("As circunferências não são internas!!!\n");
    }
    if(isTan){
        printf("As circunferências são tangentes!!!\n");
    }else{
        printf("As circunferências não são tangentes!!!\n");
    }
    if(isSec){
        printf("As circunferências são secantes!!!\n");
    }else{
        printf("As circunferências não são secantes!!!\n");
    }
    if(isExt){
        printf("As circunferências são externas!!!\n");
    }else{
        printf("As circunferências não são externas!!!\n");
    }
    return 0;
}


```

### Questão 10:
```
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _JOGADOR{
    int pontos;
    char nome[42];
} JOGADOR;

int main(){
    int i,j;
    JOGADOR *jogadores;
    jogadores = (JOGADOR *) malloc (sizeof (JOGADOR)*DIM);

    for (i = 0; i < DIM; i++){
        printf("Por favor, digite o nome do jogador: ");
        fgets((jogadores + i) ->nome, 42 ,stdin);
        for(j=0; j<42; j++){
            if((jogadores+i)->nome[j] == '\n' ||(jogadores+i) ->nome[j] == '\0') {
                (jogadores+i)->nome[j] = '\0';
                break;
            }
        }
        printf("Por favor, digite quantos pontos esse jogador tem: ");
        scanf("%d",&((jogadores + i)->pontos));
        while(getchar() != '\n');

    }
    for (i = 0; i < DIM; i++){
        printf("o jogador %s teve %d pontos\n", (jogadores+i)->nome,(jogadores+i)->pontos);
    }
    

    return 0;
}
```

### Questão 11:
```
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _JOGADOR{
    int pontos;
    char nome[42];
} JOGADOR;

int comparaJogador(JOGADOR j1, JOGADOR j2){
    int maior=0;
    if (j1.pontos>j2.pontos){
        maior = 1;
    }else if(j1.pontos<j2.pontos){
        maior = -1;
    }
    return maior;
}
int merge(JOGADOR *array, int comeco, int meio, int fim){
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;
    JOGADOR *vetorEsquerda,*vetorDireita;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;
    vetorEsquerda = (JOGADOR *) malloc (tamanhoEsquerda*sizeof( JOGADOR ));
    vetorDireita = (JOGADOR *) malloc (tamanhoDireita*sizeof( JOGADOR )); 
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
    }
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
    }
    for(i=comeco;i<=(fim);i++){
        if(topoEsquerda <= tamanhoEsquerda){
            array[i] = vetorDireita[topoDireita];
            topoDireita ++;
        }
        else if(topoDireita <= tamanhoDireita){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else if(comparaJogador(vetorEsquerda[topoEsquerda],vetorDireita[topoDireita]) <0){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else{
            array[i] = vetorDireita[topoDireita];
            topoDireita++;
        }
    }
    free(vetorEsquerda);
    free(vetorDireita);
    return 0;
}

int mergeSort( JOGADOR *array, int comeco, int fim){
    int meio;
    if(comeco<fim){
        meio = (comeco+fim)/2;
        mergeSort(array,comeco,meio);
        mergeSort(array,meio+1,fim);
        merge(array, comeco, meio, fim);
    }
    return 0;
}



int main(){
    int i,j;
    JOGADOR *jogadores;
    jogadores = ( JOGADOR *) malloc ( sizeof (JOGADOR)*DIM);

    for (i = 0; i < DIM; i++){
        printf("Por favor, digite o nome do jogador: ");
        fgets((jogadores + i)->nome, 42 ,stdin);
        for(j=0; j<42; j++){
            if((jogadores+i)->nome[j] == '\n' ||(jogadores+i) ->nome[j] == '\0') {
                (jogadores+i)->nome[j] = '\0';
                break;
            }
        }

        printf("Por favor, digite quantos pontos esse jogador tem: ");
        scanf("%d",&((jogadores + i)->pontos));
        while(getchar() != '\n');
    }
    mergeSort(jogadores,0,DIM-1);
    for (i = 0; i < DIM; i++){
        printf("o jogador %s teve %d pontos\n", (jogadores+i)->nome,(jogadores+i)->pontos);
    }
    

    return 0;
}
```

### Questão 12:
```
#include <stdio.h>
#include <stdlib.h>
#define DIM 3
typedef struct _JOGADOR{
    int pontos;
    char nome[42];
} JOGADOR;

int comparaJogador(JOGADOR j1, JOGADOR j2){
    int maior=0;
    if (j1.pontos>j2.pontos){
        maior = 1;
    }else if(j1.pontos<j2.pontos){
        maior = -1;
    }
    return maior;
}
int merge(JOGADOR *array, int comeco, int meio, int fim){
    int tamanhoEsquerda,tamanhoDireita,i,topoEsquerda=0,topoDireita=0;
    JOGADOR *vetorEsquerda,*vetorDireita;

    tamanhoEsquerda = meio-comeco+1;
    tamanhoDireita = fim - meio;
    vetorEsquerda = (JOGADOR *) malloc (tamanhoEsquerda*sizeof( JOGADOR ));
    vetorDireita = (JOGADOR *) malloc (tamanhoDireita*sizeof( JOGADOR )); 
    for(i=0;i<tamanhoEsquerda;i++){
        vetorEsquerda[i] = *(array + comeco + i);
    }
    for(i=0;i<tamanhoDireita;i++){
        vetorDireita[i] = *(array + meio + 1 + i);
    }
    for(i=comeco;i<=(fim);i++){
        if(topoEsquerda >= tamanhoEsquerda){
            array[i] = vetorDireita[topoDireita];
            topoDireita ++;
        }
        else if(topoDireita >= tamanhoDireita){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else if(comparaJogador(vetorEsquerda[topoEsquerda],vetorDireita[topoDireita]) <0){
            array[i] = vetorEsquerda[topoEsquerda];
            topoEsquerda++;
        }
        else{
            array[i] = vetorDireita[topoDireita];
            topoDireita++;
        }
    }
    free(vetorEsquerda);
    free(vetorDireita);
    return 0;
}

int mergeSort( JOGADOR *array, int comeco, int fim){
    int meio;
    if(comeco<fim){
        meio = (comeco+fim)/2;
        mergeSort(array,comeco,meio);
        mergeSort(array,meio+1,fim);
        merge(array, comeco, meio, fim);
    }
    return 0;
}



int main(){
    int i,j;
    JOGADOR *jogadores;
    jogadores = ( JOGADOR *) malloc ( sizeof (JOGADOR)*DIM);

    for (i = 0; i < DIM; i++){
        printf("Por favor, digite o nome do jogador: ");
        fgets((jogadores + i) ->nome, 42 ,stdin);
        for(j=0; j<42; j++){
            if((jogadores+i)->nome[j] == '\n' ||(jogadores+i) ->nome[j] == '\0') {
                (jogadores+i)->nome[j] = '\0';
                break;
            }
        }

        printf("Por favor, digite quantos pontos esse jogador tem: ");
        scanf("%d",&((jogadores + i)->pontos));
        while(getchar() != '\n');
    }
    mergeSort(jogadores,0,DIM-1);
    for (i = 0; i < DIM; i++){
        printf("o jogador %s teve %d pontos\n", (jogadores+i)->nome,(jogadores+i)->pontos);
    }
    for(i=0; i<(DIM-1); i++){
        *((jogadores + (i))) = *(jogadores + (i + 1));
    }
    while(1){
    printf("Por favor, digite o nome do jogador (recordista): ");
    fgets((jogadores + DIM - 1) ->nome, 42 ,stdin);
    for(j=0; j<42; j++){
        if((jogadores+ DIM - 1)->nome[j] == '\n' ||(jogadores+ DIM - 1) ->nome[j] == '\0') {
            (jogadores+ DIM - 1)->nome[j] = '\0';
            break;
        }
    }

    printf("Por favor, digite quantos pontos esse jogador tem: ");
    scanf("%d",&((jogadores + DIM - 1)->pontos));
    while(getchar() != '\n');
    if(((jogadores + DIM - 1)->pontos) > (jogadores + DIM - 2)->pontos) break;
    }

    for (i = 0; i < DIM; i++){
        printf("o jogador %s teve %d pontos\n", (jogadores+i)->nome,(jogadores+i)->pontos);
    }

    

    return 0;
}

```

### Questão 13:
```
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _FRACAO{
    int numerador , denominador;
} FRACAO;


int soma(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if(fracao2->numerador ==0){
        fracao3->numerador =  fracao1->numerador;
        fracao3->denominador = fracao1->denominador;
        return 1;
    }
        if(fracao1->numerador ==0){
        fracao3->numerador =  fracao2->numerador;
        fracao3->denominador = fracao2->denominador;
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->denominador + fracao2->numerador * fracao1->denominador;
    fracao3->denominador = fracao2->denominador * fracao1->denominador;
    return 0;
}
int subtracao(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if(fracao2->numerador ==0){
        fracao3->numerador =  fracao1->numerador;
        fracao3->denominador = fracao1->denominador;
        return 1;
    }
        if(fracao1->numerador ==0){
        fracao3->numerador =  fracao2->numerador;
        fracao3->denominador = fracao2->denominador;
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->denominador - fracao2->numerador * fracao1->denominador;
    fracao3->denominador = fracao2->denominador * fracao1->denominador;
    return 0;
}
int produto(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if(fracao2->numerador ==0){
        fracao3->numerador =  fracao1->numerador;
        fracao3->denominador = fracao1->denominador;
        return 1;
    }
        if(fracao1->numerador ==0){
        fracao3->numerador =  fracao2->numerador;
        fracao3->denominador = fracao2->denominador;
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->numerador;
    fracao3->denominador = fracao2->denominador * fracao1->denominador;
    return 0;
}
int divisao(FRACAO *fracao1, FRACAO *fracao2, FRACAO *fracao3){
    if( fracao2->numerador ==0){
        printf("po, quando divide com numerador da fracao 2 como 0 gera divisão de 0, foi mal\n");
        return 1;
    }
    fracao3->numerador =  fracao1->numerador * fracao2->denominador;
    fracao3->denominador = fracao2->numerador * fracao1->denominador;
    return 0;
}
int main(){
    int i=0;
    FRACAO *fracoes;    
    fracoes = ( FRACAO *) malloc ( sizeof (FRACAO)*DIM);
    while (1){
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &((fracoes+i)->numerador), &((fracoes+i)->denominador));
        i++;
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &((fracoes+i)->numerador), &((fracoes+i)->denominador));
        i++;
        if((fracoes)->denominador ==0 || ((fracoes+1)->denominador ==0)){
            printf("Divisão por zero não dá.\n");
            i = i-2;
        }else{
            break;
        }
}
    
    printf("As fracoes são: %d/%d e %d/%d\n", (fracoes->numerador), (fracoes->denominador), ((fracoes+1)->numerador), ((fracoes+1)->denominador));
    soma(fracoes,fracoes+1, fracoes+i);
    printf("A soma dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    i++;
    subtracao(fracoes,fracoes+1, fracoes+i);
    printf("A subtração dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    i++;
    produto(fracoes,fracoes+1, fracoes+i);
    printf("A produto dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    i++;

    if(!divisao(fracoes,fracoes+1, fracoes+i)){
        printf("A divisao dá: %d/%d\n", ((fracoes+i)->numerador), ((fracoes+i)->denominador));
    }
    i++;
    return 0;
}

```
### Questão 14:
```
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef struct _FRACAO{
    int numerador , denominador;
} FRACAO;


FRACAO soma(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if(fracao2->numerador ==0){
        fracao3.numerador =  fracao1->numerador;
        fracao3.denominador = fracao1->denominador;
        return fracao3;
    }
        if(fracao1->numerador ==0){
        fracao3.numerador =  fracao2->numerador;
        fracao3.denominador = fracao2->denominador;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->denominador + fracao2->numerador * fracao1->denominador;
    fracao3.denominador = fracao2->denominador * fracao1->denominador;
    return fracao3;
}
FRACAO subtracao(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if(fracao2->numerador ==0){
        fracao3.numerador =  fracao1->numerador;
        fracao3.denominador = fracao1->denominador;
        return fracao3;
    }
        if(fracao1->numerador ==0){
        fracao3.numerador =  fracao2->numerador;
        fracao3.denominador = fracao2->denominador;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->denominador - fracao2->numerador * fracao1->denominador;
    fracao3.denominador = fracao2->denominador * fracao1->denominador;
    return fracao3;
}
FRACAO produto(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if(fracao2->numerador ==0){
        fracao3.numerador =  fracao1->numerador;
        fracao3.denominador = fracao1->denominador;
        return fracao3;
    }
        if(fracao1->numerador ==0){
        fracao3.numerador =  fracao2->numerador;
        fracao3.denominador = fracao2->denominador;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->numerador;
    fracao3.denominador = fracao2->denominador * fracao1->denominador;
    return fracao3;
}
FRACAO divisao(FRACAO *fracao1, FRACAO *fracao2){
    FRACAO fracao3;
    if( fracao2->numerador ==0){
        printf("po, quando divide com numerador da fracao 2 como 0 gera divisão de 0, foi mal\n");
        fracao3.numerador =   0;
        fracao3.denominador = 0;
        return fracao3;
    }
    fracao3.numerador =  fracao1->numerador * fracao2->denominador;
    fracao3.denominador = fracao2->numerador * fracao1->denominador;
    return fracao3;
}
int main(){
    FRACAO fracao1, fracao2,fracSoma,fracSubtracao,fracProduto,fracDivisao;    
    while (1){
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &(fracao1.numerador), &(fracao1.denominador));
        printf("Por favor, digite a primeira fracao no seguinte formato (ex 1/1): ");
        scanf("%d/%d", &(fracao2.numerador), &(fracao2.denominador));
        if(fracao1.denominador ==0 || (fracao2.denominador ==0)){
            printf("Divisão por zero não dá.\n");
        }else{
            break;
        }
}
    
    printf("As fracoes são: %d/%d e %d/%d\n", (fracao1.numerador), (fracao1.denominador), (fracao2.numerador), (fracao2.denominador));
    fracSoma = soma(&fracao1,&fracao2);
    printf("A soma dá: %d/%d\n", (fracSoma.numerador), (fracSoma.denominador));
    fracSubtracao = subtracao(&fracao1,&fracao2);
    printf("A subtração dá: %d/%d\n", (fracSubtracao.numerador), (fracSubtracao.denominador));
    fracProduto = produto(&fracao1,&fracao2);
    printf("A produto dá: %d/%d\n", (fracProduto.numerador), (fracProduto.denominador));
    fracDivisao = divisao(&fracao1,&fracao2);
    if(fracDivisao.denominador){
        printf("A divisao dá: %d/%d\n", (fracDivisao.numerador), (fracDivisao.denominador));
    }
    return 0;
}

```