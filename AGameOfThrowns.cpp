#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n,k;

    cin >> n >> k;

    if(n < 1 || k < 1 || n > 30 || k > 100){
        return 1;
    }

    stack<int> operations;
    operations.push(0);

    for(int i = 0; i < k; i++){
        string op;
        cin >> op;

        if(op != "undo" && (stoi(op) > 10000 || stoi(op) < -10000)){
            return 1;
        }

        if(op == "undo"){
            int undonumber;
            cin >> undonumber;
            if(undonumber > 10000 || undonumber < -10000){
                return 1;
            }
            for(int j = 0; j < undonumber; j++){
                if(operations.size() > 1){
                    operations.pop();
                }
            }
        }else{
            int number = stoi(op);
            int aux = operations.top();
            int result = ((aux + number) % n + n) % n;
            operations.push(result);
        }
    }

    cout << operations.top() << endl;


    return 0;
}