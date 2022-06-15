// Name: Igor de Andrade Assunção de Almeida
//Dre: 121095736
#include <iostream>
#include <string.h>


using namespace std;


int splitLine(string line,int poss, int **adj){
    string temp="";
    cout << line << endl;
    int i=0;
    int k=0;
    for (int i = 0; i < (int)line.size(); i++){
        if(line[i] != ' ' ){
            temp += line[i];
        }else{
            adj[poss][k] = stoi(temp);
            k++;
            temp = "";
        }
    }
        adj[poss][k] = stoi(temp);
        k++;
        for (int j = 0; j < k; j++){
            cout << adj[poss][j] << " ";
        }
        cout << endl;
    return 0;
}


int main(int argc, char const *argv[]){
    string s;
    getline(cin,s);
    char *line;
    int size = s[0] - 48;
    int **adj = (int **) malloc(sizeof(int) * size) ;
    for(int i=0; i<size;i++){
        adj[i] = (int *) malloc(sizeof(int) * size);
    }
    while(getline(cin,s)){
        splitLine(s, 0, adj);
        
    }
    return 0;
}
