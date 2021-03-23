#include <iostream>
#include <memory.h>
using namespace std;

int dp[100];
int DP(int now) {
	if (now == 1) return dp[1] = 1;
	else if (now == 2) return dp[now] = 2;
	else if (now == 3) return dp[now] = 4;
	else if (dp[now] != -1) return dp[now];
	else {
		return dp[now] = DP(now - 3) + DP(now - 2) + DP(now - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC; cin >> TC;
	memset(dp, -1, sizeof(dp));
	while (TC--) {
		int N; cin >> N;
		cout << DP(N)<<"\n";
	}

	return 0;
}