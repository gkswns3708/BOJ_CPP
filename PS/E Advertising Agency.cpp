#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> qo[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	for (int i = 1; i <= 200000; i++) {
		for (int j = i * 2; j <= 200000; j += i)
			qo[i].push_back(j);
	}

	int TC; cin >> TC;
	while (TC--) {
		vector<int> num(200001);
		vector<int> dp(200001);
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int t; cin >> t; 
			num[t]++;
		}
		for (int i = 200000; i >= 1; i--) {
			for (int j : qo[i]) dp[i] = max(dp[i],dp[j]);
			dp[i] += num[i];
		}
		cout << n - dp[1]<<"\n";
	}
	return 0;
}