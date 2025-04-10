//2024 3.
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	
	reverse(s.begin(),s.end());
	
	for(int i = 0;i < n;i++){
		int add = 0;
		for(int j = 0;j < (int)s.size();j++){
			if(s[j] != '.'){
				int x = (s[j] - '0') * 2 + add;
				s[j] = '0' + x % 10;
				add = x / 10;
			}
		}
		while(add > 0){
			s += '0' + add % 10;
			add /= 10;
		}
	}
	
	int add = 0;
	
	for(int i = 0;i < (int)s.size();i++){
		if(s[i] == '.'){
			add = (s[i-1] - '0' > 4);
			continue;
		}
		int x = s[i] - '0' + add;
		s[i] = '0' + x % 10;
		add = x / 10;
	}
	
	while(add > 0){
		s += '0' + add % 10;
		add /= 10;
	}
	
	while(s.back() == 0){
		s.pop_back();
	}
	
	if(s.back() == '.'){
		s += '0';
	}
	
	reverse(s.begin(),s.end());
	
	for(int i = 0;i < (int)s.size() && s[i] != '.';i++){
		cout << s[i];
	}
	
	return 0;
} 
