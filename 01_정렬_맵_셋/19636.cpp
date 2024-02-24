#include <iostream>
#include <map>
#include <cmath>

using namespace std;

//체중 계산 요소
int forCalc(int energy_intake, int base_metabolism, int acitivity_metabolism){
    //일일 에너지 섭취량-(기초 대사량+활동 대사량)
    int energy_consumption=base_metabolism+acitivity_metabolism;
    int calc=energy_intake-energy_consumption;

    return calc;  
}

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int input1, input2, input3;

    cin >>input1>>input2>>input3;
    int w=input1;
    int base=input2; //일일 기초 대사량
    int intake=input2; //일일 에너지 섭취량
    int limit=input3; ////기초 대사량 변화 역치
    
    cin >> input1 >> input2 >> input3;
    int time=input1; //다이어트 기간
    int after_intake=input2; //일일 에너지 섭취량
    int activity=input3; //일일 활동 대사량

    int w1=w; //기초 대사량 변화 고려 X
    int w2=w; //기초 대사량 변화 고려 O
    
    int after_base=base;


    int calc=forCalc(after_intake, base, activity);

    while(time--){
    //기초 대사량 변화 고려 안하는 경우
       w1+=calc;
       int cal=forCalc(after_intake, after_base, activity);

        w2+=cal;

        if(abs(cal)>limit){
            after_base+=floor(cal/2.0);
        }

    }
    
    string result;
    if((intake-after_base)>0){
        result="YOYO";
    }else{
        result="NO";
    }

    //기초대사량 변화 고려 안한 체중
    if(w1<=0){
        cout<<"Danger Diet";
    }else{
        cout << w1 <<" "<< base;
    }

    if(w2<=0 || after_base<=0){
        cout <<"\n" << "Danger Diet"; 
    }else{
        cout << "\n" << w2 << " " << after_base <<" " << result; 
    }
}