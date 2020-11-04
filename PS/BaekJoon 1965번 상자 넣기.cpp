#pragma once
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;

int dp[1000 + 1];
int arr[1000 + 1];
int main(void) {
	fastio;
	int N; cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) cin >> arr[i];
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}