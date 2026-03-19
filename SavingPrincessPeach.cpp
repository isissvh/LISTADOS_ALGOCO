#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Y;

    cin >> N >> Y;

    if(N <= 0 || Y < 0 || N > 100 || Y > 200){
        return 1;
    }

    vector<bool> obstacle(N, false);

    for(int i = 0; i < Y; i++){
        int k;
        cin >> k;
        obstacle[k] = true;
    }

    int count = 0;

    for(int i = 0; i < N; i++){
        if(!obstacle[i]){
            cout << i << endl;
        }else{
            count++;
        }
    }

    cout << "Mario got " << count << " of the dangerous obstacles." << endl;

    return 0;
}