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
#define int long long int

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N, K;
int cost[100 + 1][100000 + 1];
vector<tuple<int, int, int, int>> vec;
void input() {
	cin >> N >> K;
	vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		vec[i] = { a,b,c,d };
	}
}

void solution() {
	auto [f1, f2, f3, f4] = vec[1];
	cost[1][f1] = f2;
	cost[1][f3] = max(cost[1][f3], f4);
	for (int i = 2; i <= N; i++) {
		auto [n1, n2, n3, n4] = vec[i];
		for (int j = 1; j <= K; j++) {
			if (cost[i - 1][j] == 0) continue;
			else {
				if (j + n1 <= K) cost[i][j + n1] = max(cost[i][j + n1], cost[i-1][j] + n2);
				if (j + n3 <= K) cost[i][j + n3] = max(cost[i][j + n3], cost[i-1][j] + n4);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= K; i++) ans = max(cost[N][i], ans);
	cout << ans;
}

int32_t main() {
	fastio;
	input();
	solution();
}