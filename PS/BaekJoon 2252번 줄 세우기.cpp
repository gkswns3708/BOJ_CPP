#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

vector<int> edge[32000 + 1];
int level[32000 + 1];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		edge[A].push_back(B);
		level[B]++;
	}
	queue<int> que;
	vector<int> ans;
	for (int i = 1; i <= N; i++) if (level[i] == 0)que.push(i), ans.push_back(i);
	
	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		for (auto nxt : edge[now]) if (--level[nxt] == 0) que.push(nxt), ans.push_back(nxt);
	}

	for (auto now : ans) cout << now << " ";
	return 0;
}