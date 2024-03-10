#include <iostream>
#include <map>
#include <ctime>
#include <vector>

using namespace std;

typedef pair<int, char> numch;
const int ALPHA =26;

//바퀴 출력하기 위한 함수
string printWheel(int n, int index, vector<char>& wheel){
    //리턴 결과로 사용한 string
    string result="";

    //시계 방향으로 원판이 회전하므로 index는 하나씩 작아짐 
    //-> index가 음수가 될 수도 있으므로 초깃값인 index에 바퀴의 칸 개수인 n을 더해줌.
    //->n을 더했으므로 i가 index까지 하나씩 감소
    for(int i=index+n; i> index; i--){
        result+=wheel[i%n];//i가 wheel의 index를 초과하지 않도록 바퀴의 칸 개수인 n으로 나눔. 
    }
    return result;
}

//바퀴의 알파벳 추측하는 함수
string calWheel(int n, int k, vector<numch> &array){
    //시작할 때 바퀴의 모든 칸을 '?'로 채워줌. 
    vector<char> wheel(n, '?');
    //해당 바퀴가 사용됐는지 알려줌. 
    vector<bool> is_available(ALPHA, false);

    int index=0;

    string result;

    for(int i=0; i<k;i++){
        int s=array[i].first;
        char ch=array[i].second;

        //index가 음수가 되는 걸 방지하기 위해 
        //index에 화살표가 회전한 횟수를 더해주고 전체 바퀴의 칸 수인 n으로 나눠줌. 
        index=(index+s)%n;

        //바퀴에 있는 글자와 겹치는 경우->오류 아님. 
        if(wheel[index]==ch){
            continue;
        }
        //해당 칸이 다른 글자로 채워진 경우 -> 위 if문을 통해 ch가 다르다는 것을 확인했으므로 '?'가 아닌지 확인. 
        //해당 글자가 이미 사용된 알파벳인 경우 -> is_available을 통해 해당 함수가 사용됐는지 확인. 
        //(is_available[0]은 'A'를 의미, is_available[1]은 의미, is_available[25]는 'Z'를 의미.) 

        if(wheel[index]!='?' || is_available[ch-'A']){        
            return "!"; //오류 발생시 "!" 출력. 
        }
       
        //위 if문에 해당 안되는 경우 -> 삽입
        wheel[index]=ch;
        is_available[ch-'A']=true;
    }
    //바퀴의 모든 칸을 result 변수에 담아 반환. 
    result=printWheel(n,index, wheel);
    return result;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력받기
    int n, k;
    cin >> n >> k;

    //s, ch를 정의하는 벡터. 
    vector<numch> array(k);

     //k번 s와 알파벳 입력받기. 
    for(int i=0; i<k; i++){
        cin >> array[i].first >> array[i].second;
    }

    //바퀴의 모든 알파벳 출력. 
    cout << calWheel(n,k, array);

    return 0;

}