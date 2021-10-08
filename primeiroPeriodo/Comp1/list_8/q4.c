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