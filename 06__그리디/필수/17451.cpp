#include <iostream>
#include <vector>
#include <cmath>
#define MAX 300000
using namespace std;

double v[MAX];

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    double temp, db;     

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    temp=v[n-1];

    for(int i=n-2; i>=0; i--){
        
       temp=ceil(temp/v[i])*v[i];
    }
    
    cout << (long long)temp;
    

    return 0;
}