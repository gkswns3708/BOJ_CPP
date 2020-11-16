#include <bits/stdc++.h>
using namespace std;

int N; 

int depth[100000 + 1];
int parent[100000 + 1][20];
bool visited[100000 + 1];
vector<int> edge[100000 + 1];

void DFS(int pos, int dep) {
	visited[pos] = true;
	depth[pos] = dep;
	for (auto a : edge[pos]) {
		if (!visited[a]) {
			parent[a][0] = pos;
			DFS(a, dep + 1);
		}
	}
}

void maketable() {
	for (int i = 1; i < 20; i++) 
		for (int j = 1; j <= N; j++) 
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
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
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	DFS(1, 0);
	maketable();

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		bool check = false;
		int r, u, v; cin >> r >> u >> v;
		int lcaru, lcarv, lcauv,lcacr;
		lcauv = lca(u, v);
		lcaru = lca(r, u);
		lcarv = lca(r, v);
		lcacr = lca(lcauv, r);
		if (depth[lcacr] < depth[lcauv]) cout << lcauv << "\n";
		else cout << (depth[lcaru] > depth[lcarv] ? lcaru : lcarv )<< "\n";	
	}
	return 0;
}