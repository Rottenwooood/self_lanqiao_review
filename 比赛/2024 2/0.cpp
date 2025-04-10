//ËØÊıÉ¸
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int primes[N],cnt = 0;
bool notPrimes[N]{};

void getPrimes(int n){
	for(int i = 2;i < n;i++){
		if(notPrimes[i]){
			continue;
		}
		primes[++cnt] = i;
		for(int j = i + i;j < n;j += i){
			notPrimes[j] = true;
		}
	}
}

int main(){
	int n;
	cin >> n;
	getPrimes(n);
	for(int i = 1;i <= cnt;i++){
		cout << primes[i] << " ";
	}
	return 0;
} 
