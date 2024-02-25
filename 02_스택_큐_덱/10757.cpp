#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){

    string temp;

    deque<int> a;
    deque<int> b;
    deque<int> s;
 
    int t1,t2;
    cin >> temp;

   
    for(char c:temp){
        t1=c-'0';
        a.push_back(t1);
    }
 
    cin >> temp;

    for(char c:temp){
        t1=c-'0';
        b.push_back(t1);
    }

    int carry=0, remain=0;
    int sum=0;

    while(!a.empty()||!b.empty()||carry){

        sum=carry;

        if(!a.empty()){
            t1=a.back();
            sum+=t1;
            a.pop_back();
        }
        if(!b.empty()){
            t2=b.back();
            sum+=t2;
            b.pop_back();
        }
        
        carry=sum/10;
        remain=sum%10;

        s.push_front(remain);
    } 
        
    while(!s.empty()){
        cout << s.front();
        s.pop_front(); 
    }
    

    return 0;

}