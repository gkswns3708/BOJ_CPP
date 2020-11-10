#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

ll mulmod(ll x, ll y, ll mod) {
	x %= mod, y %= mod;
	if (mod <= 1e9 + 9) return x * y % mod;
	ll ret = 0;
	while (x > 0) {
		if (x & 1) {
			ret += y;
			if (ret >= mod) ret -= mod;
		}
		x >>= 1, y <<= 1;
		if (y >= mod) y -= mod;
	}
	return ret;
}

namespace miller_rabin {
	ll ipow(ll x, ll y, ll p) {
		ll ret = 1, piv = x % p;
		while (y) {
			if (y & 1) ret = mulmod(ret, piv, p);
			piv = mulmod(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(ll x, ll a) {
		if (x % a == 0) return 0;
		ll d = x - 1;
		while (1) {
			ll tmp = ipow(a, d, x);
			if (d & 1) return (tmp != 1 && tmp != x - 1);
			else if (tmp == x - 1) return 0;
			d >>= 1;
		}
	}
	bool isprime(ll x) {
		for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
			if (x == i) return 1;
			if (x > 40 && miller_rabin(x, i)) return 0;
		}
		if (x <= 40) return 0;
		return 1;
	}
}

namespace pollard_rho {
	ll f(ll x, ll n, ll c) { return (c + mulmod(x, x, n)) % n; }
	void rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (miller_rabin::isprime(n)) {
			v.push_back(n);
			return;
		}
		ll a, b, c;
		while (1) {
			a = rand() % (n - 2) + 2;
			b = a;
			c = rand() % 20 + 1;
			do {
				a = f(a, n, c);
				b = f(f(b, n, c), n, c);
			} while (gcd(abs(a - b), n) == 1);
			if (a != b) break;
		}
		ll x = gcd(abs(a - b), n);
		rec(x, v);
		rec(n / x, v);
	}
	vector<ll> factorize(ll n) {
		vector<ll> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
	fastio;
	ll n, cnt = 0; cin >> n;
	//폴라드로 소인수 분해 알고리즘으로 소인수 분해 실행
	vector<ll> v = pollard_rho::factorize(n);
	//그 값을 유일하게 unique 단일화
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int bit = 1; bit < (1 << v.size()); bit++) {
		int temp = 0;
		//temp를 표현 즉 있는 것들을 이용해 temp값을 표현.
		//n
		for (int i = 0; i < v.size(); i++) if (bit & (1 << i)) temp++;
		cnt += (__builtin_popcount(bit) %2 == 1? 1 : -1) * n / temp;
	}
	cout << n - cnt << '\n';
}