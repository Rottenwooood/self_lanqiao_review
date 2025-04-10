//Ë«Ö¸Õë 
#include <bits/stdc++.h>

using namespace std;

int k;
char a,b;
string s;
int main(){
	cin >> k >> s >> a >> b;
	long long n = s.size();
	long long arr[n];
	long long cnt = 0;
	long long ans = 0;
	
	for(int i = n - 1;i >= 0;i--){
		arr[i] = s[i] == b ? ++cnt : cnt;
	}
	
	for(int i = 0;i < n;i++){
		if(s[i] == a && i + k - 1 < n) ans += arr[i + k - 1];
	}
	
	cout << ans;
	return 0;
} 
