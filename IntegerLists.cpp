#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    if(n < 1 || n > 100){
        return 1;
    }

    for(int i = 0; i < n; i++){
        string instructions;
        cin >> instructions;

        if(instructions.length() < 1 || instructions.length() > 100000){
            return 1;
        }

        int length;
        cin >> length;

        if(length < 0 || length > 100000){
            return 1;
        }

        int Ds = count(instructions.begin(), instructions.end(), 'D');
        if(Ds > length){
            cout << "error" << endl;
            string trash;
            cin >> trash;
            continue;
        }else if(Ds == length){
            cout << "[]" << endl;
            string trash;
            cin >> trash;
            continue;
        }

        vector<int> values;
        queue<char> bapq;

        for(char c : instructions){
            bapq.push(c);
        }

        string list;
        cin >> list;
        string aux = "";

        for(char j : list){
            if(isdigit(j)){
                aux += j;
            } else {
                if(!aux.empty()){
                    values.push_back(stoi(aux));
                    aux.clear();
                }
            }
        }

        if(Ds == 0){
            int Rs = count(instructions.begin(), instructions.end(), 'R');
            if(Rs % 2 == 0){
                cout << list << endl;
                continue;
            }else{
                reverse(values.begin(), values.end());
                cout << "[";
                for(size_t i = 0; i < values.size(); ++i){
                    cout << values[i];
                    if(i < values.size() - 1){
                        cout << ",";
                    }
                }
                cout << "]" << endl;
                continue;
            }
        }

        bool reversed = false;
        int left = 0;
        int right = values.size() - 1;

        while (!bapq.empty()) {
            char c = bapq.front();

            if(c == 'R'){
                reversed = !reversed;
            }else if(c == 'D'){
                if(!reversed){
                    left++;
                }else{
                    right--;
                }
            }

            bapq.pop();
        }

        cout << "[";

        if(!reversed){
            for(int j = left; j <= right; j++){
                cout << values[j];
                if(j < right){
                    cout << ",";
                }
            }
        }else{
            for(int j = right; j >= left; j--){
                cout << values[j];
                if(j > left){
                    cout << ",";
                }
            }
        }

        cout << "]" << endl;
    }

    return 0;
}