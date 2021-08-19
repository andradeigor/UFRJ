#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int i, n;
    int max = 100;
    srand(time(NULL));
    for (i=0; i<10; i++){
        n= rand();
        n = n%max;
        printf("%d \n", n);
    }
    return 0;
}
