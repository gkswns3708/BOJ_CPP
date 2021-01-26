#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


bool visited[300001];
vector<int> edge[300001];
int ans[300001];

void DFS1(int v) {
	visited[v] = 1;
	for (auto nv : edge[v])
		if (!visited[nv]) DFS1(nv);
}

void DFS2(int v) {
	visited[v] = 1;
	bool flag = true;
	for (int nowv : edge[v]) {
		if (ans[nowv] == 1) flag = false;
	}
	if (flag) ans[v] = 1;
	else ans[v] = 0;

	for (int nowv : edge[v]) {
		if (!visited[nowv]) DFS2(nowv);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			edge[i].clear();
			visited[i] = 0;
			ans[i] = -1;
		}

		for (int i = 0; i < m; i++) {
			int from, to; cin >> from >> to;
			edge[from].push_back(to);
			edge[to].push_back(from);
		}
		bool hasAns = true;
		DFS1(1);
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) hasAns = false;
			visited[i] = 0;
		}
		if (!hasAns) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";

		DFS2(1);
		vector<int> res;
		for (int i = 1; i <= n; i++) {
			if (ans[i]) res.push_back(i);
		}
		cout << res.size() << "\n";
		for (auto a : res)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}