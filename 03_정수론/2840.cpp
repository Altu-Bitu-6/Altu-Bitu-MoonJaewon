#include <iostream>
#include <map>
#include <ctime>

using namespace std;

map<int, char> getArray(int a){

    srand(time(NULL));

    map<int,char> array;

    for(int i=0; i<a; i++){
        array[i]='a'+rand()%26;
    }

    return array;
}


void show(int b, map<int, char> num){

    int index=1;

    for(int i=0; i<b; i++){
        int ran=rand()%b;

        char ch=map[ran];

        index=index-ran;


    }

}

int main(){
    int a, b;
    cin >> a >> b;
    
    map<int,char> array=getArray(a);


    
    

}