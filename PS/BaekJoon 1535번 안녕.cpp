#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int L[20 + 1];
int J[20 + 1];
int dp[100 + 1];
int N;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i];
	for (int i = 1; i <= N; i++) cin >> J[i];
}

void solution() {
	for (int i = 1; i <= N; i++) for (int j = 100; j > L[i]; j--) dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
	cout << dp[100];
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}