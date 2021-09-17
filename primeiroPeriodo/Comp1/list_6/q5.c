#include <stdio.h>
#include <string.h>
int Mystrlen(char string[]){
    int size =0;
    while (1){
        if(string[size] =='\0') {    
            break;
        }
        size+=1;
    }
    return size;
}
int Mystrcmp(char string1[], char string2[]){
    int size1, size2;
    size1 = Mystrlen(string1);
    size2 = Mystrlen(string2);
    if(size1 <size2) return -1;
    if(size1 >size2) return 1;
    return 0;
    
}
char Mystrcat(char string1[], char string2[]){
    int size1,size2,i;
    size1 = Mystrlen(string1);
    size2 = Mystrlen(string2);
    char newString[size1+size2];
    for(i=0;i<size1;i++){
        newString[i] = string1[i];
    }
    puts(newString);
    return *newString;
}
int main(){
    char v1[10] = "123454321";
    char v2[5] = "0987";
    printf("o tamanho de v1 é: %d\n", Mystrlen(v1));
    printf("o tamanho de v2 é: %d\n", Mystrlen(v2));
    printf("a comparação é %d\n", Mystrcmp(v1,v2));
    char newTest[25];
    newTest = Mystrcat(v1,v2);  
    return 0;
}