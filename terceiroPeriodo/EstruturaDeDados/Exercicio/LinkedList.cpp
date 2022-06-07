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
int main(int argc, char const *argv[])
{
    LinkedList list;
    list.Add(1.);
    list.Add(2.);
    list.Add(3.);
    list.Add(4.);
    list.Add(5.);
    list.Print();
    list.Reverse();
    list.Print();
}

