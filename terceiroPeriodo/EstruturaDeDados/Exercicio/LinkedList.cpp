#include <iostream>
#include <string.h>
#include <stack>
using namespace std;


typedef struct no
{
    float value;
    struct no *next;
} no;


class LinkedList{
    private:
        no *head;
        no *tail;
        int size=0;
    public:
        void Add(float value);
        void Remove(float value);
        void Print();
        void Reverse();
        void Search(float value, no *&ant, no *&pt);
};

void LinkedList::Add(float value){
    if(size == 0){
        head->value = value;
        head->next = NULL;
        tail = head;
        size ++;
    }else{
        no *new_no = (no * ) malloc(sizeof(no));
        if(new_no){
            new_no->value = value;
            new_no->next = NULL;
            tail->next = new_no;
            tail = new_no;
            size ++;
        }
    }
}

void LinkedList::Print(){
    no *current = head;
    cout << "[";
    while(current !=NULL){
        cout << current->value << ',';
        current = current->next;
    };
    cout << "]" <<endl;
}

void LinkedList::Reverse(){
    if(head->next == NULL or size == 0){
        return;
    }
    no *ant = NULL;
    no *current = head;
    while(current !=NULL){
        no *temp = (no *) malloc(sizeof(no));
        temp = current->next;
        current->next = ant;
        ant = current;
        current = temp;

    }
    no *temp = (no *) malloc(sizeof(no));
    if(temp){
        temp = head;
        head = tail;
        tail = head;

    }
}

void LinkedList::Search(float value, no *&ant, no *&pt){ 
    pt = head;
    if(!pt){
        cout << "lista vazia!" << endl; return;
    }
    ant = NULL;
    while(pt != NULL && pt->value != value){
        ant = pt;
        pt = pt->next;
    }
    return;
}
void LinkedList::Remove(float value){
    no *pt = (no *) malloc(sizeof(no));
    no *ant = (no *) malloc(sizeof(no));
    if(!pt or !ant){
        cout << "sem memória" << endl;
    }
    this->Search(value, ant, pt);
    if(pt ==NULL){
        cout <<" Valor não está na lista" << endl;
        return; // não tem o valor na lista
    }
    if(ant == NULL){
        cout << "alo" << endl;
        head = head->next;
        if(pt){
            free(pt);
        }
    }else{
        ant->next = pt->next;
        free(pt);
    }

}
int main(int argc, char const *argv[])
{
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Print();
    list.Remove(2);
    list.Print();
    list.Remove(1);
    list.Print();
    list.Remove(5);
    list.Print();
}

