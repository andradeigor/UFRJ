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
            if(topo){
                free(topo);
            }
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

/*string toPosFix(string expression){
    stack<char> pilha;
    string posfix = "";
    for(int i = 0; i < expression.length(); i++){
        if(!isalnum(expression[i])){
            posfix += expression[i];
        }
        else if(expression[i] == '('){
            pilha.push(expression[i]);
        }  
        
        else if(expression[i] == ')'){
            while(pilha.top() != '('){
                posfix += pilha.top(); pilha.pop();
            }
            pilha.pop();
        }
        else{
            while(!pilha.empty() && precedencia(pilha.top()) >= precedencia(expression[i])){
                posfix += pilha.top(); pilha.pop();
            }
            pilha.push(expression[i]);
        }
        while(!pilha.empty()){
            posfix += pilha.top(); pilha.pop();
        }
    }
    return posfix;
}*/
void infixToPostfix(char *expression[], int expressionSize){
    stack<char> st; 
    string result;
    
    for (int i = 0; i < expressionSize; i++) {
        char c = expression[i][0];
 
        // If the scanned character is
        // an operand, add it to output string.
        if (isalnum(c)){
            result += expression[i];
            result += ' ';
        }
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop();
        }
 
        // If an operator is scanned
        else {
            while (!st.empty()
                   && precedencia(expression[i][0]) <= precedencia(st.top())) {
                if (c == '^' && st.top() == '^')
                    break;
                else {
                    result += st.top();
                    result += ' ';
                    st.pop();
                }
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
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


int main(int argc, char *argv[]){
    stack<char> numbers;
    char result[100];
    char teste[100];
    char *digits[30];
    char *digit;
    int i=0;
    cin >> teste;
    substituteOperators(teste, result);
    digit = strtok(result, " ");
    while(digit){
        digits[i] = (char*) malloc(strlen(digit) * sizeof(char));
        strcpy(digits[i], digit);
        digit = strtok(NULL, " ");
        i++;
    }
    infixToPostfix(digits, i);

    //string posfix = toPosFix(expresion);
    //cout << posfix << endl;
   return 0;
}
