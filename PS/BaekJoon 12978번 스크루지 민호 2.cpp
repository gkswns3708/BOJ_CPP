#include <bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

vector<int> edge1[100000 + 1];
vector<int> edge[100000 + 1];
int dp[100000 + 1][2];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N - 1; i++) {
		//cout << N << " " << i << "\n";
		int u, v; cin >> u >> v;
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}

	function <void(int, int)> make_tree = [&](int root, int prev)->void {
		if (prev != 0) edge[prev].push_back(root);
		for (auto now : edge1[root]) {
			if (now != prev) make_tree(now, root);
		}
	};
	make_tree(1, 0);
	
	memset(dp, -1, sizeof dp);

	function <int(int, bool)> DP = [&](int root, bool status)->int {
		if (edge[root].empty()) return status;

		int& ret = dp[root][status];
		if (ret != -1) return ret;

		if (status) {
			ret = 1;
			for (auto now : edge[root]) ret += min(DP(now, 0), DP(now, 1));
		}
		else {
			ret = 0;
			for (auto now : edge[root]) ret += DP(now, 1);
		}
		return ret;
	};
	cout << min(DP(1, 0), DP(1, 1));

	return 0;
}