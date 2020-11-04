#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;
int N;
int dp[40 + 1];
int check[40 + 1];
void cal() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];
}
int main(void) {
	fastio;
	cin >> N;
	int K; cin >> K;
	cal();
	int ans = 1,end,postend = 0;
	vector<int> vec;
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= K; i++) {
		cin >> end;
		ans *= dp[end -postend-1];
		postend = end;
	}
	ans *= dp[N - postend];
	cout << ans;
	return 0;
}