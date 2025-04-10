#include <bits/stdc++.h>

using namespace std;

const int N = 1030;
int d[N],dt[N]; 
int main(){
//	int n;
//	double d;
//	cin >> n >> d;
//	int num = 1;
//	while(n--){
//		num <<= 1;
//	}
//	d = d * num;
//	int tmp = (int)d;
//	if(d - (double)tmp >= 0.5){
//		tmp++;
//	}
//	cout << tmp;
//	return 0;
	int n;
	cin >> n;
	char tmp;
	int point;
	int i = 0;
	while(cin >> tmp){
		if(tmp == '.'){
			point = i;
			continue;
		}
		d[i] = tmp - '0';
		i++;
	}
	int l = i;
	int num = 1;
	while(n--){
		num <<= 1;
	}
	while(l){
		int t = d[l] * num;
		int count = 0;
		while(t){
			dt[l]
		}
	}
}
