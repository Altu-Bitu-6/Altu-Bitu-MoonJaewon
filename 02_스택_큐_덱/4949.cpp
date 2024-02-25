#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool check(string input){

    stack<char> b;

    for(char c: input){
            if(c=='('|| c=='['){
                b.push(c);
            }
            else if(c==')'){
                if(!b.empty() && b.top()=='('){
                    b.pop();
                }else{
                     //오른쪽에 괄호가 더 있는 경우
                    return false;
                }
            }
            else if(c==']'){
                if(!b.empty() && b.top()=='['){
                    b.pop();
                }
                else{
                     //오른쪽에 괄호가 더 있는 경우
                    return false;
                }
            }
        
    }
    if(b.empty()){
        return true;
    }else{
        return false;
    }


}
int main(){
   
    string input;

    while(true){

    getline(cin, input);

    if(input==".") break;

        if(check(input)){
            cout << "yes\n";
            
        }else{
            cout << "no\n" ;
           
        }
    }
 return 0;
}