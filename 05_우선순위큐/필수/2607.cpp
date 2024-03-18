#include <iostream>
#include <queue>

using namespace std;

int checkSame(int n, string input){
    int len, ts_len;
    int similar=0;
    string temp;

    int al[26]={0};
    len=input.size();

    for(int i=0; i<len; i++){
        al[input[i]-'A']++;
    }
    
    for(int i=0; i<n-1; i++){
        cin >> temp;
        ts_len=temp.size();
        int same=0;

        int ts_al[26];

        for(int i=0; i<26; ++i){
            ts_al[i]=al[i];
        }

        for(int i=0; i<ts_len; i++){

            if(ts_al[temp[i]-'A']>0){
                ts_al[temp[i]-'A']--;
                same++;
            }
        }

        if(len==ts_len){
            if(same==len || same==len-1){
                similar++;
            }
        }else if(len-1==ts_len && same==len-1){
            similar++;
        }else if(len+1==ts_len && same==len){
            similar++;
        }
    }

    return similar;
    
    
    

}


int main(){

    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    string input;

    cin >> n;
    cin >> input;

    cout << checkSame(n, input);

   

}