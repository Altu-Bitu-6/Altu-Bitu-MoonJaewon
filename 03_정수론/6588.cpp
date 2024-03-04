#include <iostream>
#include <vector>

const int MAX_SIZE=1000000;

using namespace std;

void findPrime(vector<bool> &is_prime) {

    for (int i = 2; i*i<= MAX_SIZE; i++) {
        if (!is_prime[i]) { 
            continue;
        }
        for(int j=i*i; j<=MAX_SIZE; j+=i){
            is_prime[j]=false;
        }
    }

}


int main(){

    vector<bool> is_prime(MAX_SIZE+1, true);  //우선 소수로 설정
    findPrime(is_prime);
    vector<int> order;
    int n;

    string result;

    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        order.push_back(n);
    }
    for(int j=0; j<order.size(); j++){
        n=order.at(j);
        bool check=false;

        for(int i=3;i<n;i+=2){
            if(is_prime[i]&&is_prime[n-i]){//i + (n-i)=n  //가장 크게 차이날 때
                cout << n << " = " << i << " + " << n-i << "\n"; 
                check=true;
                break;
            }
        }
        if(!check){
            cout << "Goldbach's conjecture is wrong.";
        }
    }

    return 0;
}