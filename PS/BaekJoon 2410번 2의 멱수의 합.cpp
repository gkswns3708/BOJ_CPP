#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long int ll;
#define INF 5000001
int N;
int dp[1000000 + 1];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= N; i *= 2)
		for (int j = i; j <= N; j++)
			dp[j] = (dp[j] + dp[j - i]) % 1000000000;
	cout << dp[N];
	return 0;
}
