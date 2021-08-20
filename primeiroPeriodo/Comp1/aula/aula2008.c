#include <stdio.h>


int main(){
    int i, v[5] = {1,2,3,4,5};

    for(i=0;i<5;i++){
        printf("o endereço é %X e o valor é %d\n",v+i,*(v+i));
    }
    return 0;
}