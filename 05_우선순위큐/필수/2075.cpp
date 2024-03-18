#include <iostream>
#include <queue>

using namespace std;

int findNum(int N){
    priority_queue<int, vector<int>, greater<int>> mh;

     int size=N*N;
     int x;

    while(size--){
        cin >> x;
        mh.push(x);

        if(mh.size()>N){
            mh.pop();
        }
    }
    return mh.top();

}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;
   
    cout << findNum(N);

    return 0;
}