#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;



int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	int dp[10000 + 1][4] = { 0, };
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i < 10001; i++) {
		dp[i][1] = 1;
		dp[i][2] = 1 + dp[i - 2][2];
		dp[i][3] = 1 + dp[i - 3][2] + dp[i - 3][3];
	}
	while (TC--) {
		int n; cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}
	return 0;
}