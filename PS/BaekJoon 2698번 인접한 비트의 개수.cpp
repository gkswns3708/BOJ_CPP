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

int n, k;
int dp[100+1][100+1][2];
void prepare() {
	
	//±âÀú»ç·Ê
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	for (int k = 0; k < 100; k++) {
		for (int n = 2; n <= 100; n++) {
			if (k == 0) dp[n][k][1] += dp[n - 1][k][0];
			else dp[n][k][1] += dp[n - 1][k][0] + dp[n - 1][k - 1][1];
			dp[n][k][0] += dp[n - 1][k][0] + dp[n - 1][k][1];
		}
	}
}




int main() {
	fastio;
	int TC; cin >> TC;
	prepare();
	while (TC--) {
		int n, k; cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}
}