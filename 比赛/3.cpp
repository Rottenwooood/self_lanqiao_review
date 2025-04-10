//3.บรสý
#include <bits/stdc++.h>

using namespace std;

bool isGood(int num){
	while(num){
		int t1 = num % 10;
		int t2 = num / 10 % 10;
		if(t1 % 2 == 0 || t2 % 2 == 1){
			return false;
		}
		num /= 100;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1;i <= n ;i++){
		if(isGood(i)){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
