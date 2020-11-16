#include <bits/stdc++.h>
using namespace std;

int N;
int visited[100000 + 1];
int parent[100000 + 1][22];
int mn[101010][22];
int mx[101010][22];
int depth[100000 + 1];
int dist[100000 + 1];
vector<pair<int, int>> vec[100000 + 1];

void DFS(int pos, int dp, int dst) {
	visited[pos] = true;
	depth[pos] = dp;
	dist[pos] = dst;
	for (auto a : vec[pos]) {
		if (!visited[a.first]) {
			parent[a.first][0] = pos;
			mn[a.first][0] = mx[a.first][0] = a.second;
			DFS(a.first, dp + 1, dst + a.second);
		}
	}
}
void maketree() {
	for (int i = 1; i < 22; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			mn[j][i] = min(mn[j][i - 1], mn[parent[j][i - 1]][i - 1]);
			mx[j][i] = max(mx[j][i - 1], mx[parent[j][i - 1]][i - 1]);
		}
	}
}

pair<int,int> lca(int first, int second) {
	int l = INT_MAX;
	int r = INT_MIN;
	if (depth[first] < depth[second]) swap(first, second);
	int gap = depth[first] - depth[second];
	for (int i = 0; gap; i++) {
		if (gap & 1) {
			l = min(l, mn[first][i]);
			r = max(r, mx[first][i]);
			first = parent[first][i];
		}
		gap >>= 1;
	}
	if (first == second) return {l,r};
	for (int i = 21; i >= 0; i--) {
		if (parent[first][i] != parent[second][i]) {
			l = min({ l,mn[first][i],mn[second][i] });
			r = max({ r,mx[first][i],mx[second][i] });
			first = parent[first][i];
			second = parent[second][i];
		}
	}
	l = min({ l,mn[first][0], mn[second][0] });
	r = max({ r,mx[first][0], mx[second][0] });
	return {l,r};
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from, to, length; cin >> from >> to >> length;
		vec[from].push_back({ to,length });
		vec[to].push_back({ from,length });
	}
	DFS(1, 0, 0);
	maketree();

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		pair<int, int> ans = lca(a, b);
		cout <<ans.first <<" " << ans.second << "\n";
	}
	return 0;
}