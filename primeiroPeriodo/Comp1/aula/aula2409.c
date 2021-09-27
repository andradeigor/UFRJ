# include <stdio.h>
# include <stdlib.h>
int main (void ) {
float *v; int i , tam ;
printf (" Qual o tamanho do vetor ? ");
scanf ("%d", & tam );
v = calloc ( tam , sizeof( float));
if (! v) {
return 1;
}
for (i =0; i < tam ; i ++) {
printf (" Elemento %d ?", i );
scanf ("%f", v+i);
printf (" Li valor %f \n", *( v+i));
}
free (v);
return 0;
}