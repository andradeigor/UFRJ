// Name: Igor de Andrade Assunção de Almeida
//Dre: 121095736
#include <iostream>
#include <string.h>


using namespace std;


int splitLine(string line,int poss ){
    string temp="";
    for (int i = 0; i < line.size(); i++){
        if(line[i] != (char) " " ){
            temp += line[i];
        }else{
            cout << temp << endl;
            temp = "";
        }
    }
    return 0;
}


int main(int argc, char const *argv[]){
    string s;
    getline(cin,s);
    char *line;
    int size = s[0] - 48;
    cout << size << endl;
    while(getline(cin,s)){
        splitLine(line, 1);
        while(line){
            cout << line << endl;
            line = strtok(NULL, " ");
        }
    }
    return 0;
}
