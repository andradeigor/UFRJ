// Name: Igor de Andrade Assunção de Almeida
//Dre: 121095736
#include <iostream>
#include <string.h>


using namespace std;


int splitLine(string line,int poss, int **adj, int *adjNumber, int *conectionNumber){
    string temp="";
    int k=0;
    int tempNumber;
    for (int i = 0; i < (int)line.size(); i++){
        if(line[i] != ' ' ){
            temp += line[i];
        }else{
            tempNumber = stoi(temp) ;
            adj[poss][k] = tempNumber;
            conectionNumber[k] +=1;
            adjNumber[tempNumber] +=1;
            k++;
            temp = "";
        }
    }
        tempNumber = stoi(temp) ;
        adj[poss][k] = tempNumber;
        adjNumber[tempNumber] +=1;
        conectionNumber[k] +=1;
        k++;
        for (int j = 0; j < k; j++){
            cout << adj[poss][j] << " ";
        }
        cout << endl;
    return 0;
}


int main(int argc, char const *argv[]){
    string s;
    int size, index=0;
    getline(cin,s);
    size = s[0] - 48;
    int **adj = (int **) malloc(sizeof(int) * size);

    int conectionNumber[size];
    int adjNumber[size];
    if(conectionNumber == NULL or adjNumber==NULL or adj==NULL){
        cout << "ERRO, SEM MEMORIA" << endl;
        return 1;
    }
    for(int i=0; i<size;i++){
        adj[i] = (int *) malloc(sizeof(int) * size);
        adjNumber[i]= conectionNumber[i] = 0;
    }
    
    while(getline(cin,s)){
        if(s==""){
            index++;
            continue;
        }
        splitLine(s, index, adj, adjNumber, conectionNumber);
        index++;
    }

    for (int i = 0; i < size; i++){
        cout << adjNumber[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++){
        cout << conectionNumber[i] << " ";
    }
    cout << endl;
    return 0;
}
