#include <bits/stdc++.h>
using namespace std;

int N;
int visited[30000 + 1];
int parent[30000 + 1][20];
int depth[30000 + 1];
vector<int> vec[30000 + 1];

void DFS(int pos, int dp) {
	visited[pos] = true;
	depth[pos] = dp;
	for (auto a : vec[pos]) {
		if (!visited[a]) {
			parent[a][0] = pos;
			DFS(a, dp + 1);
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
	for (int i = 0; i < N - 1; i++) {
		int from, to, length; cin >> from >> to ;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	DFS(1, 0);
	maketree();

	int m; cin >> m; 
	int first = 1;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int second; cin >> second;
		int lcaa = lca(first, second);
		sum += depth[first] + depth[second] - 2 * depth[lcaa];
		first = second;
	}
	cout << sum;
	return 0;
}