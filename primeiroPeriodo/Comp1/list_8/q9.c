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
