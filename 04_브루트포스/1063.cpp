#include <iostream>
#include <utility> // for std::pair
#include <sstream> // for std::istringstream

using namespace std;

void printResult(int N, pair<char, int>& king, pair<char,int>& rock) {
    string op;
    
    int kx = king.first - 'A';  //알파벳으로 처리하기 힘들기 때문에 'A'값에 해당하는 아스키 코드값을 빼줘서 정수형으로 만듦. 
    int ky = king.second; 
    int rx = rock.first - 'A';
    int ry = rock.second;  
    int tmpx = 0, tmpy = 0; //이동에 사용할 변수 초기화

    while (N--) { //N번 반복하는 동안 N번의 명령어 처리. 
        cin >> op;
 
        if (op == "R") {  //X축 오른쪽 방향으로 한 칸 이동 
            tmpx = 1; 
            tmpy = 0;
        } else if (op == "L") { //X축 왼쪽 방향으로 한 칸 이동
            tmpx = -1;
            tmpy = 0;
        } else if (op == "B") { //Y축 아래쪽 방향으로 한 칸 이동
            tmpx = 0;
            tmpy = -1;
        } else if (op == "T") {//Y축 위쪽 방향으로 한 칸 이동
            tmpx = 0;
            tmpy = 1;
        } else if (op == "RT") { //X축 오른쪽 방향으로 한 칸+ //Y축 위쪽 방향으로 한 칸 이동
            tmpx = 1;
            tmpy = 1;
        } else if (op == "LT") {//X축 왼쪽 방향으로 한 칸+ //Y축 위쪽 방향으로 한 칸 이동
            tmpx = -1;
            tmpy = 1;
        } else if (op == "RB") {//X축 오른쪽 방향으로 한 칸+ //Y축 아래쪽 방향으로 한 칸 이동
            tmpx = 1;
            tmpy = -1;
        } else if (op == "LB") { //X축 왼쪽 방향으로 한 칸+ //Y축 아래쪽 방향으로 한 칸 이동
            tmpx = -1;
            tmpy = -1;
        }
        
        int Kx = kx + tmpx; //King의 임시변수인 Kx에 임시로 값 할당. (기존 위치인 kx + 명령어에 해당하는 움직임)을 Kx에 대입.  
        int Ky = ky + tmpy; //마찬가지로 Ky에 임시로 값 할당. 

        //king이 움직일 때 체스판 내부에 있는지 확인. 
        if(Kx<0 || Kx >7 || Ky <1 || Ky>8){
            continue;
        }

        //돌의 움직임 확인.
        if (Kx == rx && Ky == ry) { //킹의 임시 위치와 돌의 기존 위치가 같을 때 실행
            int Rx = rx + tmpx;  //돌의 임시 x 위치 할당. (돌의 기존 위치인 rx + 명령어로 인한 움직임)을 Rx에 할당. 
            int Ry = ry + tmpy;  //돌의 임시 y 위치 할당. 

            //돌이 체스판 내부에 있다면 실행. 
            if (Rx >= 0 && Rx < 8 && Ry >= 1 && Ry <= 8) {
                rx = Rx; //돌의 임시 x 위치를 돌의 진짜 위치로 설정. 
                ry = Ry; //돌의 임시 y 위치를 돌의 진짜 위치로 설정. 
                kx=Kx; //킹의 임시 x위치를 킹의 진짜 위치로 설정. 
                ky=Ky; //킹의 임시 y위치를 킹의 진짜 위치로 설정. 
            }else{ //돌이 조건에 위배되어 움직이지 않는다면 킹 또한 움직이지 않음. 
                kx=kx; 
                ky=ky;
            }
        }else{
            kx=Kx;  //킹과 돌의 위치가 같지 않다면 킹만 이동
            ky=Ky;  //킹과 돌의 위치가 같지 않다면 킹만 이동
        }
        
    }
   //열에서의 위치 
    king.first = kx + 'A';  //숫자로 바꿨던 x축에서의 위치를 알파벳으로 다시 돌려놓음. 
    rock.first = rx + 'A';  //숫자로 바꿨던 y축에서의 위치를 알파벳으로 다시 돌려놓음. 
    
    //행에서의 위치
    king.second = ky;
    rock.second = ry;

    //결과 출력
    cout << king.first << king.second <<"\n";
    cout << rock.first << rock.second;
}

int main() {
    char king1, rock1;
    int king2, rock2;
    int N;

    //행과 열에서의 위치를 한 번에 다루기 위해 pair로 선언. 
    pair<char, int> king;  
    pair<char, int> rock;

    cin >> king1 >> king2; 
    cin >> rock1 >> rock2;
    cin >> N;

    //입력받은 값을 킹과 돌의 pair에 각각 대입. 
    king = make_pair(king1, king2);
    rock = make_pair(rock1, rock2);

    //pair값을 함수에 대입한 결과 출력. 
    printResult(N, king, rock);

    return 0;
}
