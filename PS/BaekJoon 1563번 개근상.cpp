#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define MOD 1000000
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

ll N;
ll dp[1000+1][1000+1][3][2];

ll ans(int days, int a, int b, int c) {
	if (b == 3 || c == 2) return 0;
	if (days == N) return 1;

	ll &now = dp[days][a][b][c];
	if (now != -1)
		return now;

	now = ans(days + 1, a + 1, 0, c) + ans(days + 1, a, b + 1, c) + ans(days + 1, a, 0, c + 1);
	now%= MOD;
	return now;
}

int main() {
	fastio;
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << ans(0, 0, 0, 0) << "\n";

}