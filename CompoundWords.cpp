#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main(){

    vector<string> palabras;
    set<string> compuestas;
    string s;

    while (cin >> s) {
        palabras.push_back(s);
    }
    
    int total = palabras.size();

    for(int i = 0; i < total; i++){
        for(int j = 0; j < total; j++){
            if(i != j){
                string compuesta = palabras[i] + palabras[j];
                compuestas.insert(compuesta);
            }
        }
    }

    for(string x : compuestas){
        cout << x << endl;
    }

    return 0;
}