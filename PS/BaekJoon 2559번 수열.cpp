#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321
#define int long long int

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;
	vector<int> prefix_sum(N+1);
	for (int i = 1; i <= N; i++) {
		int temp; cin >> temp;
		prefix_sum[i] += prefix_sum[i - 1] + temp;
	}
	int ans = -INF;
	for (int i = K; i < N; i++) {
		ans = max(ans, prefix_sum[i] - prefix_sum[i - K]);
	}
	cout << ans;
	return 0;
}