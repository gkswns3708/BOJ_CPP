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
	//범위 내로 들어온다면 모듈러 연산을 바로 실행함.
	ll f(ll x, ll n, ll c) { return (c + mulmod(x, x, n)) % n; }
	void rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		//2의 거듭제곱꼴을 모두 마치고 난뒤의 수가 소수인지 판별
		//소수면 바로 v.push후 종료 남은 소수를 판별할 필요가 없음
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (miller_rabin::isprime(n)) {
			v.push_back(n);
			return;
		}
		//합성수일 경우
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
	ll n; cin >> n;
	vector<ll> ans = pollard_rho::factorize(n);
	for (auto i : ans) cout << i << '\n';
	return 0;
}

