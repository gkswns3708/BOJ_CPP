#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int _gcd(int a, int b) {
	if (b == 0)  return a;
	else return _gcd(b, a % b);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, G; cin >> R >> G;
	int sqrtnum = _gcd(R,G);
	for (int i = 1; i <= sqrtnum; i++)
		if (R % i == 0 && G % i == 0) cout << i << " " << R / i << " " << G / i << '\n';
	return 0;
}