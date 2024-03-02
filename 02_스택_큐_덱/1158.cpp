#include <iostream>
#include <queue>
#define MAX_SIZE 5000

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k=0, n=0;
    cin >> n >> k;

    queue<int> q;
    int front=0, rear=0;

    for(int i=1;i<=n;i++){
        q.push(i);
    }
    cout <<"<";

    int c=0;
    --n;
    while(n--){
        for(int i=1; i<k; i++){
            c=q.front();
            q.pop();
            q.push(c);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}