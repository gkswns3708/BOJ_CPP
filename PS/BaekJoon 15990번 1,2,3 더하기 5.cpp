#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
#define MOD (int)(1e9+9)
using namespace std;
int dp[100000 + 1][4];


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	dp[1][1] = dp[2][2] = dp[3][3] = dp[3][1] = dp[3][2] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	while (TC--) {
		int n; cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3])%MOD<<"\n";
	}
	return 0;
}