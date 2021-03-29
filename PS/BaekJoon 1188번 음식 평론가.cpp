#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

int _gcd(int a, int b) {
	return b == 0 ? a : _gcd(b, a%b);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	int a = N / M, b = N % M;
	cout << M - _gcd(M, b);
	return 0;
}