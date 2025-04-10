//4.10 ¸ß¾«¶È
#include <bits/stdc++.h>

using namespace std;

vector<int> mult(vector<int>& A,int b){
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size() || t;i++){
		if(i < A.size())t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
} 

vector<int> add(vector<int>& A,vector<int>& B){
	if(A.size() < B.size()) return add(B,A);
	
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size();i++){
		t += A[i];
		if(i < B.size()) t += B[i];
		C.emplace_back(t % 10);
		t /= 10;
	}
	
	if(t)C.emplace_back(t);
	return C;
}

vector<int> minus(vector<int>& A,vector<int>& B){
	vector<int> C;
	int t = 0;
	
	for(int i = 0;i < A.size();i++){
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		C.emplace_back((t+10)%10);
		if(t < 0)t = 1;
		else t = 0;
	}
	
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

vector<int> multi(vector<int>& A,int b){
	vector<int> C;
	int t = 0;
	
	for(int i = 0;i < A.size() || t;i++){
		if(i < A.size()) t += A[i] * b;
		C.emplace_back(t % 10);
		t /= 10;
	}
	
	while(C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

int main(){
	vector<int> res;
	res.push_back(1);
	for(int i = 0;i < 37;i++){
		res = mult(res,2);
	}
	for(int i = res.size() - 1;i >= 0;i--){
		cout << res[i];
	}
	return 0;
}
