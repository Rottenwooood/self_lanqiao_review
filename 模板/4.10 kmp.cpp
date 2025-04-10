//kmp
#include <bits/stdc++.h>
using namespace std;

vector<int> buildNext(const string& pattern){
	int n = pattern.size();
	vector<int> next(n,0);
	int j = 0;
	//这里从1开始 
	for(int i = 1;i < n;i++){
		while(j > 0 && pattern[i] != pattern[j]){
			j = next[j - 1];
		}
		if(pattern[i] == pattern[j]){
			j++;
		}
		next[i] = j;
	}
	return next;
} 

vector<int> kmpSearch(const string& text,const string& pattern){
	vector<int> result;
	int j = 0;
	vector<int> next = buildNext(pattern);
	int n = text.size(),m = pattern.size();
	//这里从0开始 
	for(int i = 0;i < n;i++){
		while(j > 0 && text[i] != pattern[j]){
			j = next[j - 1];
		}
		if(text[i] == pattern[j]){
			j++;
		}
		if(j == m){
			result.push_back(i - m + 1);
			j = next[j - 1];
		}
	}
	return result;
}

int main(){
	string s,p;
	cin >> s >> p;
	vector<int> postions = kmpSearch(s,p);
	if(postions.empty()){
		cout << "None" << endl;
	}else{
		for(int pos : postions){
			cout << pos << " ";
		}
		cout << endl;
	}
	return 0;
}
