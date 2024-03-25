#include <iostream>
#include <string>
#include <cstring> 
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void makePalin(string str){
    int alp[26]={0};
    string odd,even;

    for(char c:str){
        if(isalpha(c)){
            alp[toupper(c)-'A']++;
        }
    }

    for(int i=0; i<26; i++){
        if(alp[i]%2==1){  //알파벳이 홀수 개 있을 때
            odd+=i+'A';
        }
        for(int j=0; j<alp[i]/2; j++){
            even+=i+'A';
        }
    }
    if(odd.size()>1){
        cout << "I'm Sorry Hansoo";
    }else{
    cout << even << odd;
    reverse(even.begin(), even.end());
    cout << even;
    }
}

int main(){
    ios::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    makePalin(str);

    return 0;
}