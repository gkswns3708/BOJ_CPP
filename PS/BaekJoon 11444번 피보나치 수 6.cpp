#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define int long long int
#define MOD (int)1e9+7
using namespace std;
int N;

int rc[2][2];
map<int, int> d;

int fibo(int a) {
	if (a <= 1) return a;
	else if (a == 2) return 1;
	else if (d.count(a) > 0) return d[a];
	else {
		if (a % 2 == 1) {
			int m = (a + 1) / 2;
			int t1 = fibo(m);
			int t2 = fibo(m - 1);
			d[a] = t1 * t1 + t2 * t2;
			return d[a] %= MOD;
		}
		else {
			int m = a / 2;
			int t1 = fibo(m - 1);
			int t2 = fibo(m);
			d[a] = (2 * t1 + t2) * t2;
			return d[a] %= MOD;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cout << fibo(N);
	return 0;
}