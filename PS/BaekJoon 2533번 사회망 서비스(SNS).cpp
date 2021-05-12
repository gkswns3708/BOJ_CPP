#include <bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

vector<int> edge1[1000000 + 1];
vector<int> edge[1000000 + 1];
int dp[1000000][2];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}

	function <void(int, int)> make_tree = [&](int root, int prev)->void {
		if (prev != 0) edge[prev].push_back(root);
		for (auto now : edge1[root]) if (now != prev) make_tree(now, root);
	};

	function <int(int, bool)> DP = [&](int pos, bool status)->int {
		if (edge[pos].empty()) return status ? 1 : 0;

		int& ret = dp[pos][status];
		if (ret != -1) return ret;

		if (status == 1) {
			ret = 1;
			for (auto now : edge[pos]) ret += min(DP(now, 0), DP(now, 1));
		}
		else {
			ret = 0;
			for (auto now : edge[pos]) ret += DP(now, 1);
		}

		return ret;
	};

	make_tree(1, 0);
	memset(dp, -1, sizeof(dp));
	cout << min(DP(1, 0), DP(1, 1));

	return 0;
}