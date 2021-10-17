#include <stdio.h>

int main() {
    FILE *movimento;
    int letra,movimentoValido,i;
    char movimentos[13]={"44446868"};
    i=4;
    movimento = fopen("movimentos.txt", "a+");
    fprintf(movimento,"q%s\n", movimentos);
    fprintf(movimento, "%d", i);
    fclose(movimento);
    return 0;

}