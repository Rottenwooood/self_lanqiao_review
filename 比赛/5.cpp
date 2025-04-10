//5
#include <bits/stdc++.h>

using namespace std;

int _gcd(int a,int b){
	return b == 0 ? a : _gcd(b,a % b);
}

int _lcm(int a,int b){
	return a / _gcd(a,b) * b;
}

double jisuanS(int a,int b,int c){
	return a * b * c * _lcm(_lcm(a,b),c) / _lcm(a,b) / _lcm(a,c) / _lcm(b,c);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int maxS = 0;
	int aa = 1e5,ab = 1e5,ac = 1e5;
	for(int i = 0;i < n - 2;i++){
		for(int j = i + 1;j < n - 1;j++){
			for(int k = j + 1;k < n;k++){
				double tmp = jisuanS(a[i],a[j],a[k]); 
				if(tmp > maxS){
					int arr[3] = {a[i],a[j],a[k]};
					sort(arr,arr+3);
					maxS = tmp;
					aa = arr[0];
					ab = arr[1];
					ac = arr[2];
				}else if(tmp == maxS){
					int arr[3] = {a[i],a[j],a[k]};
					sort(arr,arr+3);
					if(aa > arr[0]){
						maxS = tmp;
						aa = arr[0];
						ab = arr[1];
						ac = arr[2];
					}else if(aa == arr[0] && ab > arr[1]){
						maxS = tmp;
						aa = arr[0];
						ab = arr[1];
						ac = arr[2];
					}else if(aa == arr[0] && ab == arr[1] && ac > arr[2]){
						maxS = tmp;
						aa = arr[0];
						ab = arr[1];
						ac = arr[2];
					}
				}
			}
		}
	}
	cout << aa << " " << ab << " " << ac;
	return 0;
}
