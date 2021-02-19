#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define INF LLONG_MAX
#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N, M;
vector<pll> vec;
ll ans = INF;
ll before = -1;

void input() {
	cin >> N >> M;
	vec.resize(N);
	for (ll i = 0; i < N; i++) cin >> vec[i];
}

void solution() {
	sort(all(vec), [](const auto& a, const auto& b) {
		return ((a.second < b.second) || (a.second == b.second) && (a.first > b.first)); });
	int nw, np;
	nw = np = 0;
	for (int i = 0; i < N; i++) {
		if (nw < M) {
			if (before == vec[i].second) np += vec[i].second;
			else before = np = vec[i].second;
		}
		else {
			if ((before != vec[i].second) && (np > vec[i].second)) 	before = np = vec[i].second;
		}
		nw += vec[i].first;
	}
	if (nw < M)cout << -1;
	else cout << np; 
}

int main() {
	fastio;
	input();
	solution();
}