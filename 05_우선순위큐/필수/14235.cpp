#include <iostream>
#include <queue>

using namespace std;

void printGift(int n){
    int temp;
    int gift;
    priority_queue<int> pq;
     
    while(n--){

        cin >> temp;

        if(temp==0){
            if(pq.empty()){
                cout << "-1" << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
            
        }
        else{
            while(temp--){
                cin >> gift;
                pq.push(gift);
            }
        }

    }
}

int main(){

    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    printGift(n);
    return 0;
}