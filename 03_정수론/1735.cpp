#include <iostream>
#include <algorithm>

using namespace std;

//최대공약수 구하기
int getGCD(int a, int b){
    for(int i=min(a,b); i>0; i++){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

int main(){
    int a,b;
    int m,n;


    cin >> a>> b;
    cin >> m >> n; 

    //최대공약수 구하기
    int GCD=getGCD(b,n);
    int LCM=b*n/GCD;

    a*=(LCM/b);
    m*=(LCM/n);
    
    cout << a+m <<"  "<< LCM;

   return 0;  

}