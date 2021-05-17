#include <bits/stdc++.h>
#define int uint64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MOD (1LL*1000000007)
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		int ans = 1;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			pq.push(num);
		}
		ans = 1;
		while (pq.size() >  1) {
			int num1 = pq.top();pq.pop();
			num1 *= pq.top();pq.pop();
			ans = num1 % MOD * ans % MOD;
			pq.push(num1);
		}
		ans %= MOD;
		cout << ans << "\n";
	}
	return 0;
}