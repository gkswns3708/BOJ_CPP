#include <bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int value[200000 + 1];

int dp[200000 + 1][2];

vector<int> edge1[200000 + 1];
vector<int> edge[200000 + 1];
bool check[200000 + 1][2];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> value[i];

	memset(dp, -1, sizeof dp);
	for (int i = 2; i <= N; i++) {
		int u; cin >> u;
		edge[i].push_back(u);
		edge[u].push_back(i);
	}
	
	function <int(int,int , bool, bool)> DP = [&](int root,int prev, bool status, bool major)->int {
		int& ret = dp[root][status];
		if (edge[root].empty()) return ret = status? value[root] : 0;
		if (ret != -1) return ret;
		if (status) {
			ret = value[root];
			for (auto nxt : edge[root]) if (nxt != prev) ret += DP(nxt, root, 0, major);
		}
		else {
			ret = 0;
			for (auto nxt : edge[root]) if (nxt != prev) ret += max( DP(nxt, root, 0, major), DP(nxt, root, 1, major));
		}
		
		return ret;
	};

	cout << DP(1, 0, 1, 1)<< " " << DP(1, 0, 0, 0) << "\n";

	function<void(int, int, bool, bool)> DFS = [&](int root, int prev, bool select, bool major)->void {
		if (select) check[root][major] = 1;
		for (auto nxt : edge[root]) {
			if (nxt == prev) continue;
			if (!select && dp[nxt][1] >= dp[nxt][0]) DFS(nxt, root, 1, major);
			else DFS(nxt, root, 0, major);
		}
	};
	memset(check, 0, sizeof check);
	DFS(1, 0, 1, 1);
	for (int i = 1; i <= N; i++) if (check[i][1]) cout << i << " ";  cout << "-1\n";
	memset(check, 0, sizeof check);
	DFS(1, 0, 0, 0);
	for (int i = 1; i <= N; i++) if (check[i][0]) cout << i << " ";  cout << "-1\n";
	return 0;
}