// https://dashoj.com/d/lqbproblem/p/196
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dx = 15, dy = 17;
ll width = 343720 * 2, height = 233333 * 2;

ll gcd(ll a, ll b) { // 最大公因数
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) { // 最小公倍数
	return a / gcd(a, b) * b;
}

int main() {
	cout.precision(2);
	cout << fixed;
	ll dt = lcm(dx, width) / dx;
	for (int t = dt;; t += dt) 
		if (t * dy % height == 0) {
			cout << hypot(t * dx, t * dy);
			break;
		}
	return 0;
}

