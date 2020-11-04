#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;
pair<int, int> arr[20 + 1];
int dp[20 + 1];
int main(void) {
	fastio;
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < N; i++) {
		int length = arr[i].first;
		int end = i + arr[i].first;
		int price = arr[i].second;
		if (end > N + 1) continue;
		for (int j = end; j <= N; j++) {
			dp[j] = max(dp[i] + price, dp[j]);
		}
	}
	cout << dp[N];
	return 0;
}