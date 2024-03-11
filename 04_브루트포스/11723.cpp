#include <iostream>
#include <vector>

using namespace std;

void printResult(int M){

    int num=0;
    string op;
    int x;

    while (M--) {
        cin >> op;

        if (op == "add") {
            cin >> x;
            num|=1 << x;
        } else if (op == "remove") {
            cin >> x;
            num &=~(1 << x);
        } else if (op == "check") {
            cin >> x;
            int check=1<<x;
            
            if ((num & check) == (1<<x)) {
                cout << "1" << "\n";
            } else {
                cout << "0" << "\n";
            }
        } else if (op == "toggle") {
            cin >> x;
            
            if ((num  & (1<<x))==(1<<x)) {
                num &=~(1 << x);
            } else {
               num |=1<<x;
            }
        } else if (op == "all") {
            num=(1 << 21) - 1;
        } else if (op == "empty") {
            num=0;
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M;

    cin >> M;

    
    printResult(M);

    return 0;
}