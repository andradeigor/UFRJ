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
};

int Pilha::push(float value){
    if(size == 0){
        ptno *new_node = new ptno;
        topo->value = value;
        topo->next = new_node;
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
        ptno *aux = topo;
        topo = topo->next;
        free(aux);
        return value;
    }
}

int main(int argc, char const *argv[]){
    Pilha pilha;
    float value = pilha.pop();
    pilha.push(1);
    pilha.push(2);
    cout << pilha.top() << endl;
    cout << value << endl;
    return 0;
}
