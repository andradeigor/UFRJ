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
    printf("Por favor, digite a segunda coordenada x,y (ex:1,1): ");
    scanf("%f,%f", &coord2.x,&coord2.y);
    printf("A distância entre %1.1f,%1.1f e %1.1f,%1.1f é %1.2f\n", coord1.x,coord1.y,coord2.x,coord2.y, distancia(coord1.x,coord1.y,coord2.x,coord2.y));

    return 0;
}