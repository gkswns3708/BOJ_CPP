#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
namespace miller_rabin {
	ull  power(ull  x, ull  y, ull  mod) {
		ull  temp = 1;
		x %= mod;
		while (y) {
			if (y & 1) temp = (temp * x) % mod;
			y /= 2;
			x = (x * x) % mod;
		}
		return temp;
	}

	bool miller_rabin(ull n, ull a) {
		//n <= 2�� ��� ���� ó��.
		if (n <= 1) return false;
		if (n == 2) return true;

		//a % n == 0�� ���� �丣���� �������� ����� �� �����Ƿ� ���� ó��.
		if (n == a) return true;

		//a % n != 0�� ���.
		ull k = n - 1;
		while (1) {
			ull temp = power(a, k, n);
			if (temp == n - 1) return true;
			if (k & 1) return temp == 1 || temp == n - 1;
			k /= 2;
		}
	}

	bool isprime(ull  x) {
		for (auto i : {2,7,61 }) {
			if (!miller_rabin(x, i)) return false;
		}
		return true;
	}
}

int main() {
	fastio;
	ull n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		ull temp; cin >> temp;
		if (miller_rabin::isprime(temp * 2 + 1)) {

			ans++;
		}
	}
	cout << ans;
	return 0;
}