#include <iostream>
#include <memory.h>
#define int long long
#define MOD 1000000009
using namespace std;

int dp[1000000+1];
int DP(int now) {
	if (now <= 3) return dp[now];
	for (int i = 4; i <= now; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%MOD;
	}
	return dp[now];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC; cin >> TC;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (TC--) {
		int N; cin >> N;
		cout << DP(N) << "\n";
	}

	return 0;
}