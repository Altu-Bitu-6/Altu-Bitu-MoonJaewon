#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


bool compare(string s1, string s2) {

	if (s1.length() != s2.length()) {
		return s1.length()<s2.length();
	}

	int count_s1=0, count_s2=0;
	
	//문자열에서 숫자의 합 세기
	for(int i=0; i<s1.length();i++){
		if(s1[i]>='0'&& s1[i]<='9'){
			count_s1+=s1[i]-'0';
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			count_s2+=s2[i]-'0';
		}
	}
	if (count_s1 != count_s2) {
		return count_s1<count_s2;
	}
	
	//s1과 s2 사전순으로 비교
	return s1<s2;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string serial;
	vector<string> list;
	

	for (int i = 0; i < n; i++) {
		cin >> serial;
		list.push_back(serial);
	}

	sort(list.begin(), list.end(), compare);

	for (auto iter = list.begin(); iter != list.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;

}