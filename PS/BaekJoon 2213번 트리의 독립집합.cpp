#include <bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int value[10000 + 1];
int dp[10000 + 1][2];
bool check[10000 + 1];

vector<int> edge1[10000 + 1];
vector<int> edge[10000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> value[i];
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edge1[u].push_back(v);
		edge1[v].push_back(u);
	}
	
	function <void(int, int)> make_tree = [&](int root, int prev)->void {
		if (prev != 0) edge[prev].push_back(root);
		for (auto nxt : edge1[root]) if (nxt != prev) make_tree(nxt, root);
	};


	function <int(int, bool)> DP = [&](int root, bool status)->int {
		int& ret = dp[root][status];
		if (edge[root].empty()) return ret = status ? value[root] : 0;
		if (ret != -1) return ret;
		if (status) {
			ret = value[root];
			for (auto nxt : edge[root]) ret += DP(nxt, 0);
		}
		else {
			ret = 0;
			for (auto nxt : edge[root]) ret += max(DP(nxt, 0), DP(nxt, 1));
		}
		return ret;
	};

	function <void(int, int ,bool)> DFS = [&](int root,int prev,bool select)->void {
		if (select) check[root] = 1;
		for (auto nxt : edge[root]) {
			if (nxt == prev) continue;
			if (!select && dp[nxt][1] >= dp[nxt][0]) DFS(nxt, root, 1);
			else  DFS(nxt, root, 0);
		}
	};

	make_tree(1, 0);
	memset(dp, -1, sizeof dp);
	int ans = max(DP(1, 0), DP(1, 1));

	if (ans == DP(1, 0)) DFS(1, 0, 0);
	else DFS(1, 0, 1);
	cout << ans << "\n";
	for (int i = 1; i <= N; i++) if (check[i]) cout << i << " ";
	return 0;
}