#include <stdio.h>
#include <stdlib.h>

int verif_par (int valor);  

int main (int argc, char *argv []) {
     int i, numero;

     if (argc < 2) {   
        printf ("Por favor digite os números como argumentos do programa\n");
        return 1; 
     }
     else { 
        for (i=1; i < argc; i++) { 
             numero = atoi (argv[i]); 
             if (verif_par (numero) == 0)
                 printf ("o valor lido %d é par\n", numero);
             else 
                 printf ("o valor lido %d é ímpar\n", numero);
         } 
     }
     return 0; 
}

int verif_par (int valor) {
    return (valor % 2);
}
