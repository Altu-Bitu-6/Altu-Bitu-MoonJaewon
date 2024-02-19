#include <iostream>
#include <map>
#include <string.h>


using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m;
    string input;

    cin >> n >> m;

    int check=0;
    map<string, int> prepare;

    while(n--){
        cin >> input;
        prepare[input]=1;
    }
    while(m--){
        cin >> input;
        if(prepare[input]==1){
            check++;
        }
        
    }

    cout << check;

    return 0;
    
}