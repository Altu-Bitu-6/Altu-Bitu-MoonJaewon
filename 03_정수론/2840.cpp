#include <iostream>
#include <map>
#include <ctime>
#include <vector>

using namespace std;

typedef pair<int, char> numch;
const int ALPHA =26;

string printWheel(int n, int index, vector<char>& wheel){
    string result="";

    for(int i=index+n; i> index; i--){
        result+=wheel[i%n];
    }
    return result;
}

string calWheel(int n, int k, vector<numch> &array){
    vector<char> wheel(n, '?');
    vector<bool> is_available(ALPHA, false);

    int index=0;

    string result;

    for(int i=0; i<k;i++){
        int s=array[i].first;
        char ch=array[i].second;

        index=(index+s)%n;

        //바퀴에 있는 글자와 겹치는 경우
        if(wheel[index]==ch){
            continue;
        }
        //해당 칸이 다른 글자로 채워진 경우
        //해당 글자가 이미 사용된 알파벳인 경우

        if(wheel[index]!='?' || is_available[ch-'A']){
            return "!";
        }
       
        //삽입할 수 있는 경우
        wheel[index]=ch;
        is_available[ch-'A']=true;
    }

    result=printWheel(n,index, wheel);
    return result;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력받기
    int n, k;
    cin >> n >> k;


    vector<numch> array(k);
    vector<char> wheel(n, '?');
    map<char, bool> use;
     
    for(int i=0; i<k; i++){
        cin >> array[i].first >> array[i].second;
    }
    cout << calWheel(n,k, array);

    return 0;

}