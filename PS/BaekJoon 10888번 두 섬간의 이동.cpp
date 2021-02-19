#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

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

ll N,ans1,ans2;
ll parents[100000+1];
ll cost[100000+1];

ll Q1(ll n) {
	return n * (n - 1) / 2;
}

ll Q2(ll n) {
	return n * (n - 1) * (n + 1) / 6;
}

ll _Find(ll x) {
	return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(ll a, ll b) {
	a = _Find(a), b = _Find(b);
	if (a == b) return;
	if (a < b) swap(a, b);
	parents[b] = a;
	cost[a] += cost[b];
}

int main() {
	fastio;
	cin >> N;
	for (int i = 1; i <= N; i++) cost[i] = 1;
	ans1 = 0; ans2 = 0;
	for (ll i = 1; i <= N; i++) parents[i] = i;
	for (ll i = 0; i < N-1; i++) {
		ll a, b; cin >> a;
		b = a + 1;
		a = _Find(a), b = _Find(b);
		if (a != b) {
			ans1 -= Q1(cost[a]) + Q1(cost[b]);
			ans2 -= Q2(cost[a]) + Q2(cost[b]);
			_Union(a, b);
			a = _Find(a);
			ans1 += Q1(cost[a]);
			ans2 += Q2(cost[a]);
		}
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}