#include <bits/stdc++.h>
using namespace std;

int N;
int visited[40000 + 1];
int parent[40000 + 1][20];
int depth[40000 + 1];
int dist[40000 + 1];
vector<pair<int,int>> vec[40000 + 1];

void DFS(int pos, int dp,int dst) {
	visited[pos] = true;
	depth[pos] = dp;
	dist[pos] = dst;
	for (auto a : vec[pos]) {
		if (!visited[a.first]) {
			parent[a.first][0] = pos;
			DFS(a.first, dp + 1,dst+a.second);
		}
	}
}
void maketree() {
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

int lca(int first, int second) {
	if (depth[first] < depth[second]) swap(first, second);
	int gap = depth[first] - depth[second];
	for (int i = 0; gap; i++) {
		if (gap & 1) first = parent[first][i];
		gap >>= 1;
	}
	if (first == second) return first;
	for (int i = 19; i >= 0; i--) {
		if (parent[first][i] != parent[second][i]) {
			first = parent[first][i];
			second = parent[second][i];
		}
	}
	return parent[first][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	depth[1] = 0; parent[1][0] = 0; visited[1] = 1; dist[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		int from, to,length; cin >> from >> to >> length;
		vec[from].push_back({ to,length });
		vec[to].push_back({ from,length });
	}
	DFS(1, 0, 0);
	maketree();

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << dist[a] + dist[b] - 2*dist[lca(a, b)] << "\n";
	}
	return 0;
}