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
typedef struct ptno2{
    float value;
    struct ptno2 *next;
} ptno2;
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
        ptno *new_no = (ptno *) malloc(sizeof(ptno));
        if(new_no){
        new_no->value = value;
        new_no->next = topo;
        topo = new_no;
        size++;
        return 0;
        }else{
            cout << "Sem memória" << endl;
            return 1;
        }
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
            topo = (ptno *) malloc(sizeof(ptno));
            size--;
            return value;
        }else{
            ptno *aux = (ptno *) malloc(sizeof(ptno));
            aux = topo;
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
class Pilha2{
    private:
        ptno2 *topo;
        int size = 0;
    public:
        int push(float value);
        float pop();
        float top();
        int isEmpty();
};

int Pilha2::push(float value){
    if(size == 0){
        topo->value = value;
        topo->next = NULL;
        size++;
        return 0;
    }else{
        ptno2 *new_no = (ptno2 *) malloc(sizeof(ptno2));
        if(new_no){
        new_no->value = value;
        new_no->next = topo;
        topo = new_no;
        size++;
        return 0;
        }else{
            cout << "Sem memória" << endl;
            return 1;
        }
    }
}
float Pilha2::top(){
    return topo->value;
}

float Pilha2::pop(){
    if(size == 0){
        cout << "Pilha vazia" << endl;
        return 0;
    }else{
        float value = topo->value;
        if(size == 1){
            topo = (ptno2 *) malloc(sizeof(ptno2));
            size--;
            return value;
        }else{
            ptno2 *aux = (ptno2 *) malloc(sizeof(ptno2));
            aux = topo;
            topo = topo->next;
            if(aux){
                free(aux);
            }
            size--;
            return value;
        }
    }
}




/*
<--------------------Definição das duas pilhas----------------------->
*/
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

string infixToPostfix(char *expression[], int expressionSize){
    Pilha pilha; 
    string result;
    
    for (int i = 0; i < expressionSize; i++) {
        char digit = expression[i][0];
 
        if (isalnum(digit)){
            result += expression[i];
            result += ' ';
        }
 
        else if (digit == '(')
            pilha.push('(');
 
        else if (digit == ')') {
            while (pilha.top() != '(') {
                result += pilha.top();
                result += ' ';
                pilha.pop();
            }
            pilha.pop();
        }else {
            while (!pilha.isEmpty()
                   && precedencia(expression[i][0]) <= precedencia(pilha.top())) {
                if (digit == '^' && pilha.top() == '^')
                    break;
                else {
                    result += pilha.top();
                    result += ' ';
                    pilha.pop();
                }
            }
            pilha.push(digit);
        }
    }
    while (!pilha.isEmpty()) {
        result += pilha.top();
        result += ' ';
        pilha.pop();
    }
 
    return result;
}

void substituteOperators(char *expression, char *result){
    int i = 0, l=0;
    
    while(expression[i] != '\0'){
            if(operatorToInt(expression[i])){
                result[l] =  ' ';
                l++;
                result[l] =  expression[i];
                l++;
                result[l] =  ' ';
            }else{
                result[l] = expression[i];
            }
        i++;
        l++;
    }
    result[l] = '\0';
}
float Evaluate(float a, float b, char op){
    switch (op){
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b / a;
    default:
        return 0;
    }
}

float Conta(char *expression){
    Pilha2 numeros;
    char *digit;
    digit = strtok(expression, " ");
    while(digit){
        if(operatorToInt(digit[0])){
            float b = numeros.top();
            numeros.pop();
            float a = numeros.top();
            numeros.pop();
            float result = Evaluate(a, b, digit[0]);
            numeros.push(result);
        }
        else{
            float numero = atof(digit);
            numeros.push(numero);
        }
        digit = strtok(NULL, " ");
    }
    float result = numeros.top();
    return result;
}

int main(int argc, char *argv[]){
    char InputTratado[100];
    char input[100];
    char *digits[30];
    char *digit;
    int i=0;
    cin >> input;
    substituteOperators(input, InputTratado);
    digit = strtok(InputTratado, " ");
    while(digit){
        digits[i] = (char*) malloc(strlen(digit) * sizeof(char));
        strcpy(digits[i], digit);
        digit = strtok(NULL, " ");
        i++;
    }
    string pósFix = infixToPostfix(digits, i);
    float resultado = Conta((char *) pósFix.c_str());
    cout << resultado << endl;
   return 0;
}
