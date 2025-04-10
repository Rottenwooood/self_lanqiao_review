//สýัง
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a,ll b){
	return b == 0 ? a : gcd(b,a % b);
}

ll lcm(ll a,ll b){
	return a / gcd(a,b) * b;
}


bool isPrime(ll num){
	if(num <= 1)return false;
	for(int i = 2;i <= num / i;i++){
		if(num % i == 0) return false;
	}
	return true;
}

const int N = 1e6;
int primes[N];
int cnt = 0;
bool notPrimes[N]{};
void getPrimes(int num){
	for(int i = 2;i <= num;i++){
		if(notPrimes[i])continue;
		primes[cnt++] = i;
		for(int j = i + i;j <= num;j += i){
			notPrimes[j] = true;
		}
	}
}

//const int N = 1e6;
//int primes[N];
//int cnt = 0;
//bool notPrimes[N]{};
void _getPrimes(int num){
	for(int i = 2;i <= num;i++){
		if(!notPrimes[i]) primes[cnt++] = i;
		for(int j = 0;primes[j] <= num / i;j++){
			notPrimes[primes[j] * i] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

ll quickPow(ll a,ll b,ll p){
	ll base = a;
	ll res = 1;
	while(b){
		if(b & 1) res = res * base % p;
		b >>= 1;
		base = base * base % p;
	}
	return res;
}

int nums[N];
bool existTarget(ll sum){
	ll target = sum >> 1;
	
	bitset<10010> dp(1);
	for(int i = 0;i < n;i++){
		dp |= dp << nums[i]; 
		if(dp[target]) return true;
	}
	return false;
}

ll C(ll a,ll b){
	ll res = 1;
	for(int i = 1,j == a;i <= b;i++){
		res = res * j / i;
	}
	return res;
}

int main(){
	int num;
	cin >> num;
	_getPrimes(num);
	for(int i = 0;i < cnt;i++){
		cout << primes[i] << " ";
	}
	
	
	return 0;
}
 
