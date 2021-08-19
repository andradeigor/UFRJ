#include <stdio.h>

int main(){
    int i=1;
    while(i<=20){

        if(i==2) {
            i++;
            continue;
        }
        if(i==5) {
            i++;
            break;
        }
        printf("i=%d\n", i);
        i++;
    }
    return 0;
}