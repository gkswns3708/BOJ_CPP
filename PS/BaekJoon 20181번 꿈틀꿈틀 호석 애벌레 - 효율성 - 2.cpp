#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int N, K;
int arr[100000 + 10], dp[100000 + 10];


int binary_search(int start) {
	int st = start - 1,ed = N+1; 
	while (st + 1 < ed) {
		int mid = (st + ed) / 2;
		if (arr[mid] - arr[start-1] >= K) ed = mid;
		else st = mid;
	}
	return ed;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int now; cin >> now;
		arr[i] = arr[i - 1] + now;
	}
	for (int i = N; i >=1; i--) {
		int ed = binary_search(i);
		dp[i] = max(dp[ed], arr[ed] - arr[i - 1] - K + dp[ed + 1]);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, dp[i]);	
	cout << ans;
	return 0;
}