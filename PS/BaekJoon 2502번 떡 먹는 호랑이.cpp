#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
typedef long long int ll;

ll fibo1[50];
ll fibo2[50];

ll fibonacci2(int n) {
	if (n == 2) return fibo2[2];
	if (n == 1) return fibo2[1];
	if (fibo2[n] != -1) return fibo2[n];
	return fibo2[n] = fibonacci2(n - 1) + fibonacci2(n - 2);
}
ll fibonacci1(int n) {
	if (n == 2) return fibo1[2];
	if (n == 1) return fibo1[1];
	if (fibo1[n] != -1) return fibo1[n];
	return fibo1[n] = fibonacci1(n - 1) + fibonacci1(n - 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(fibo1, -1, sizeof(fibo1));
	memset(fibo2, -1, sizeof(fibo2));
	fibo1[1] = 1;
	fibo1[2] = 0;
	fibo2[1] = 0;
	fibo2[2] = 1;

	fibonacci1(31);
	fibonacci2(31);
	int D,K; cin >>D >> K;
	ll a = fibo1[D];
	ll b = fibo2[D];
	//cout << a << " " << b << "-a,b\n";
	for (ll i = a; i <= K; i += a) {
		if ((K - i) % b == 0) {
			cout << i / a << "\n" << (K - i) / b << "\n";
			break;
		}
	}
	return 0;
}