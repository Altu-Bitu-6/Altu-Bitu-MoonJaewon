#include <iostream>
#include <string>

using namespace std;
const int MAX= 10000000;

string findNum(int N){

    int count=0;
    for(int i=0; i<MAX; i++){
        string numToString=to_string(i);

        if(numToString.find("666")!= string::npos){
            count++;
        }
        if(count==N){
            return numToString;
        }
    }

    return "";
}

int main(){
    int N;

    cin >> N;

    string result=findNum(N);

    cout << result;

    return 0;
}