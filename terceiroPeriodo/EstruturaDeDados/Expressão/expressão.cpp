// Name: Igor de Andrade Assunção de Almeida
//Dre: 121095736
#include <iostream>
#include <string.h>
using namespace std;

typedef struct ptno{
    float value;
    struct ptno *next;
} ptno;
class Pilha{
    private:
        ptno *topo;
        int size = 0;
    public:
        int push(float value);
        float pop();
        float top();
        int isEmpty();
};

int Pilha::push(float value){
    if(size == 0){
        topo->value = value;
        topo->next = NULL;
        size++;
        return 0;
    }else{
        ptno *new_node = new ptno;
        new_node->value = value;
        new_node->next = topo;
        topo = new_node;
        size ++;
        return 0;
    }
}
float Pilha::top(){
    return topo->value;
}
float Pilha::pop(){
    if(size == 0){
        cout << "Pilha vazia" << endl;
        return 0;
    }else{
        float value = topo->value;
        if(size == 1){
            ptno *aux = topo;
            topo = new ptno;
            size--;
            return value;
        }else{
            ptno *aux = topo;
            topo = topo->next;
            free(aux);
            size--;
            return value;
        }
    }
}
int Pilha::isEmpty(){
    return size == 0;
}

int main(int argc, char const *argv[]){
    Pilha pilha;
    pilha.push(1);
    pilha.push(2);
    cout << pilha.pop() << endl;
    cout << pilha.pop() << endl;
    cout << pilha.pop() << endl;
    pilha.push(3);
    cout << "o topo da pilha é " << pilha.top() << endl;
    cout << "o pop foi" << pilha.pop() << endl;
    cout << "o tamanho atual é " << pilha.isEmpty() << endl;
    return 0;
}
