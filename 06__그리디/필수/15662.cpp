#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1000;
deque<int> dq[MAX]; //회전한다는 점을 고려해 덱을 사용

void rotateGear(int gearNum, int direction) { //회전할 때 사용하는 메서드
    if (direction == 1) { //시계방향으로 회전
        int temp = dq[gearNum].back(); //톱니바퀴의 맨 뒤 원소를 삽입.
        dq[gearNum].pop_back(); //
        dq[gearNum].push_front(temp);
        //톱니바퀴의 맨 뒤 원소를 POP연산하고 다시 맨 앞에 삽입.
    } else { //반시계 방향으로 회전
        int temp = dq[gearNum].front(); //톱니바퀴의 맨 앞 원소를 삽입.
        dq[gearNum].pop_front();
        dq[gearNum].push_back(temp);
        //톱니바퀴의 맨 앞 원소를 POP 연산하고 다시 맨 뒤에 삽입.
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

//톱니바퀴의 개수인 T번 루프를 돌며 각 톱니바퀴의 구성요소 채움
    for (int t = 0; t < T; t++) {  
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++){
            dq[t].push_back(s[i] - '0'); 
            //아스키코드를 고려해 입력받은 값을 숫자로 제대로 인식하기 위해 0 빼줌. 
            //8개의 숫자를 한 번에 받기 때문에 int로 입력받을 수 없음.  
        }      
    }

    int K;
    cin >> K;

//회전시킬 방법이 K번 루프를 돌며 진행
    for (int k = 0; k < K; k++) {
        int num, dir;
        cin >> num >> dir;  //톱니바퀴의 번호와 방향 입력받기
        num -= 1;

        vector<pair<int, int>> v;
        v.push_back({ num, dir });
 // 현재 처리 중인 톱니바퀴의 번호(num)와 회전 방향(dir)을 pair로 묶어 벡터에 추가함


        queue<pair<int, int>> q;
        q.push({ num, dir });
        // 현재 처리 중인 톱니바퀴의 번호(num)와 회전 방향(dir)을 pair로 묶어 큐에 추가함


        bool visited[MAX] = { false, };//방문여부를 체크하는 bool 배열
        visited[num] = true; //num에 해당하는 톱니바퀴 번호를 방문했음을 의미.
       

        while (!q.empty()) {
            int cur = q.front().first;
            int d = q.front().second;
            q.pop();
            //q의 첫번째 요소를 각각 cur과 d 변수에 할당.(톱니바퀴 확인에 쓰임)
           
            //왼쪽 톱니바퀴 확인
            if (cur != 0 && dq[cur][6] != dq[cur - 1][2] && !visited[cur - 1]) {
           // 왼쪽 톱니바퀴와 현재 톱니바퀴가 서로 다른 극이고 아직 방문하지 않았다면
                visited[cur - 1] = true; //왼쪽 톱니바퀴에 방문했음을 표시
                q.push({ cur - 1, d * -1 }); //왼쪽 톱니바퀴를 반대 방향으로 회전시키기 위해 큐에 추가함
                v.push_back({ cur - 1, d * -1 }); // 회전할 톱니바퀴 번호와 회전 방향을 벡터에 추가함
            }
           
            //오른쪽 톱니바퀴 확인
            if (cur != T - 1 && dq[cur][2] != dq[cur + 1][6] && !visited[cur + 1]) {
                //오른쪽 톱니바퀴와 현재 톱톱니바퀴가 다른 극이고 아직 방문하지 않았다면면
                visited[cur + 1] = true; //오른쪽 톱니바퀴에 방문했음을 표시시
                q.push({ cur + 1, d * -1 }); //오른쪽 톱니바퀴를 반대 방향으로 회전시키기 위해 큐에 추가함.
                v.push_back({ cur + 1, d * -1 }); //회전할 톱니바퀴의 번호와 회전 방향을 벡터에 추가함.
            }
        }

        for (int i = 0; i < v.size(); i++) {
            int cur = v[i].first;
            int d = v[i].second;
            rotateGear(cur, d);
            //벡터의 첫번째 요소부터 마지막 요소까지 돌면서 회전을 실행행
        }
    }

    //12시 방향이 S극인 톱니바퀴의 개수 세기
    int result = 0;
    for (int t = 0; t < T; t++){
        if (dq[t][0] == 1)  
            result++;
    }
    cout << result << "\n";

    return 0;
}