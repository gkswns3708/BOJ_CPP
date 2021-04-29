#include <bits/stdc++.h>
#define int long long int
using namespace std;
int sz[100000 + 1];
vector<int> edge[100000 + 1];
int DFS(int root,int prv) {
	sz[root] = 1;
	for (auto nxt: edge[root]) {
		if (prv == nxt) continue;
		sz[root] += DFS(nxt,root);
	}
	return sz[root];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, R, Q; cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	DFS(R, 0);

	while (Q--) {
		int now; cin >> now;
		cout << sz[now] << "\n";
	}
	 
	return 0;
}