#include <bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int person[10000 + 1];
int dp[10000 + 1][2];

vector<int> edge1[10000 + 1];
vector<int> edge[10000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> person[i];
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}

	function <void(int, int)> make_tree = [&](int root, int prev)->void {
		if (prev != 0) edge[prev].push_back(root);
		for (auto now : edge1[root]) if (now != prev) make_tree(now, root);	
	};

	function <int(int, bool)> DP = [&](int root, bool status)->int {
		if (edge[root].empty()) return status ? person[root] : 0;

		int& ret = dp[root][status];
		if (ret != -1) return ret;

		if (status) {
			ret = person[root];
			for (auto nxt : edge[root]) ret += DP(nxt, 0);
		}
		else {
			ret = 0;
			for (auto nxt : edge[root]) ret += max(DP(nxt,0),DP(nxt, 1));
		}
		return ret;
	};

	make_tree(1, 0);
	memset(dp, -1, sizeof dp);
	cout << max(DP(1, 0),DP(1,1));

	return 0;
}