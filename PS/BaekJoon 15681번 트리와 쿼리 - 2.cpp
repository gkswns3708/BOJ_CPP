#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int sz[100000 + 1];
bool visited[100000 + 1];
vector<int> edge[100000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, R, Q; cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	fill(sz, sz + 100001, 1LL);
	function <int(int,int)> DFS = [&](int root,int prev)->int {
		for (auto now : edge[root]) {
			if (now != prev) {
				if (visited[now]) sz[root] += sz[now];
				else sz[root] += DFS(now, root),	visited[now] = 1;
			}
		}
		return sz[root];
	};

	DFS(R, -1);

	for (int i = 0; i < Q; i++) {
		int q; cin >> q;
		cout << sz[q] << "\n";
	}

	return 0;
}