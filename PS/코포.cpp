#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;


#define MOD (int)1e9+7
#define int long long int
#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N, K;

vector<int> prime;
bool is_composite[200000 + 1];

void sieve(int n) {
	fill(is_composite, is_composite + n, 0);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}


int _gcd(int a, int b) {
	if (b == 0) return a;
	else return _gcd(b, a % b);
}

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	sieve(200000);
	vector<int> vec(n);
	map<int, int> mp[200000 + 1];
	for (int i = 0; i < n; ++i) cin >> vec[i];
	for (int i = 0; i < n; ++i) {
		int temp = vec[i];
		while (temp != 1) {
			for (int j = 0; j < prime.size(); ++j) {
				if (temp % prime[j] == 0) {
					temp /= prime[j];
					mp[i][prime[j]]++;
					break;
				}
			}
		}
	}
	map<int, int> gcd;
	for (auto now : prime) gcd[now]++;
	
	for (int i = 0; i < n; i++) {
		for (auto now : mp[i]) 	gcd[now.first] = min(gcd[now.first], now.second);
	}
	while (q--) {
		int k, x; cin >> k >> x;
		map<int, int> tmp;
		while (x != 1) {
			for (int i = 0; i < prime.size(); ++i) {
				if (x % prime[i] == 0) {
					x /= prime[i];
					tmp[prime[i]]++;
				}
			}
		}
	}
	
}