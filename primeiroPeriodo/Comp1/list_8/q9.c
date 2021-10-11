#include <stdio.h>
#include <math.h>

typedef struct _CIRCUNFERENCIA{
float raio;
float x,y;
}CIRCUNFERENCIA;


int main()
{
    CIRCUNFERENCIA c1, c2;
    printf( "Entre com o raio do circulo c1 \n " );
    scanf( "%f" , &c1.raio );
    printf ( "Entre com as coordenadas do centro do circulo 1\n " );
    scanf( "%f %f" , &c1.x , &c1.y );
    printf( " Dados lidos\n " );
    printf( "Entre com o raio do circulo c1 \n " );
    scanf( "%f" , &c2.raio );
    printf ( "Entre com as coordenadas do centro do circulo 2\n " );
    scanf( "%f %f" , &c2.x , &c2.y );
    printf( " Dados lidos\n " );
    return 0;
}
