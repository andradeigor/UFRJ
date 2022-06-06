// Name: Igor de Andrade Assunção de Almeida
//Dre: 121095736
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

typedef struct ptno{
    char value;
    struct ptno *next;
} ptno;
class Pilha{
    private:
        ptno *topo;
        int size = 0;
    public:
        int push(char value);
        char pop();
        char top();
        int isEmpty();
};

int Pilha::push(char value){
    if(size == 0){
        topo->value = value;
        topo->next = NULL;
        size++;
        return 0;
    }else{
        ptno *new_no = new ptno;
        new_no->value = value;
        new_no->next = topo;
        topo = new_no;
        size++;
        return 0;
    }
}
char Pilha::top(){
    return topo->value;
}
char Pilha::pop(){
    if(size == 0){
        cout << "Pilha vazia" << endl;
        return 0;
    }else{
        char value = topo->value;
        if(size == 1){
            ptno *aux = topo;
            topo = new ptno;
            size--;
            return value;
        }else{
            ptno *aux = topo;
            topo = topo->next;
            if(aux){
                free(aux);
            }
            size--;
            return value;
        }
    }
}
int Pilha::isEmpty(){
    if(size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int precedencia(char op){
    if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}


int operatorToInt(char op){
    switch (op){
    case '+':
        return 43;
    case '-':
        return 45;
    case '*':
        return 42;
    case '/':
        return 47;
    case '(':
        return 40;
    case ')':
        return 41;
    default:
        return 0;
    }
}
Pilha InvertePilha(Pilha pilha){
    Pilha PilhaInvertida;
    while(!pilha.isEmpty()){
        PilhaInvertida.push(pilha.pop());
    }
    return PilhaInvertida;
}

string toPosFix(string expression){
    Pilha pilha;
    string posfix = "";
    for(int i = 0; i < expression.length(); i++){
        if(isalnum(expression[i])){
            posfix += expression[i];
        }
        else if(expression[i] == '('){
            pilha.push(expression[i]);
        }  
        
        else if(expression[i] == ')'){
            while(pilha.top() != '('){
                posfix += pilha.pop();
            }
            pilha.pop();
        }
        else{
            while(!pilha.isEmpty() && precedencia(pilha.top()) >= precedencia(expression[i])){
                posfix += pilha.pop();
            }
            pilha.push(expression[i]);
        }
        while(!pilha.isEmpty()){
            posfix += pilha.pop();
        }
    }
    return posfix;
}

int main(int argc, char *argv[]){
    Pilha numbers;
    char teste[210];
    cin >> teste;
    cout << teste << endl;
    for (int i = 0; i < strlen(teste); i++){
        cout << teste[i] << endl;
        numbers.push(teste[i]);
    }
    while(!numbers.isEmpty()){
        cout << numbers.isEmpty() << endl;
        cout << numbers.top() << endl;
        numbers.pop();
    }
    //string posfix = toPosFix(expresion);
    //cout << posfix << endl;
    
   return 0;
}
