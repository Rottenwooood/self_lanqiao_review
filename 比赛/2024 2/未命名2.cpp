 
#include <bits/stdc++.h>

using namespace std;
//1。快速排序
void quick_sort(int q[],int l,int r){
	if(l >= r) return;
	
	int i = l - 1,j = r + 1,x = q[l + r >> 1];
	
	while(i < j){
		do i==;while(q[i] < x);
		do j--;while(q[j] > x);
		if(i < j) swap(q[i],q[j]);
	}
	quick_sort(q,l,j),quick_sort(q,j + 1,r);
}

//2.二分 
bool check(int x){}

int bsearch_1(int l,int r){
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
//3.浮点数二分 
double bsearch(double l,double r){
	const double eps = 1e-6;
	while(r - l > eps){
		double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	return l;
}

//高精度
vector<int> add(vector<int> &A,vector<int> &B){
	if(A.size() < B.size()) return add(B,A);
	
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size();i++){
		t += A[i];
		if(i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if(t) C.push_back(t);
	return C;
} 

vector<int> add(vector<int> &A,vector<int> &B){
	if(A.size() < B.size()) return add(B,A);
	
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size();i++){
		t += A[i];
		if(i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	
	if(t) C.push_back(t);
	return C;
}
//高精度减法 
vector<int> minus(vector<int> A,vector<int> B){
	vector<int> C;
	int t = 0;
	for(int i = 0,t = 0;i < A.size();i ++){
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		C.push_back((t+10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
} 

vector<int> minus(vector<int> A,vector<int> B){
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size();i++){
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

//前缀和
S[i] = a[1] + a[2] + a[3] + ... + a[i];
a[l] + ... + a[r] = S[r] - S[l - 1]; 
int main(){
	
} 
