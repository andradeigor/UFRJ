#include <stdio.h>
typedef struct _PONTO{
float x , y;
} PONTO;
int main ( void ){
    PONTO p;
    printf ( "Entre com as coordenadas do ponto p \n" );
    scanf( "%f %f" , &p.x , &p.y);
    printf( " Dados lidos\n " );
    printf( " Ponto p:x = %f , y= % f \n " , p.x , p.y );
return 0;
}