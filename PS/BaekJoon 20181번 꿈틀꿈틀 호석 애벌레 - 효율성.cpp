#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
int arr[100000 + 1];
int dp[100000 + 1];
int N, K, l, r,sum;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int r = 1, l = 0; r <= N; r++) {
		cin >> arr[r];
		sum += arr[r];
		dp[r] = dp[r - 1];
		while (sum >= K) {
			dp[r] = max(dp[r], dp[l] + sum - K);
			sum -= arr[++l];
		}
	}
	cout << dp[N];
	return 0;
}