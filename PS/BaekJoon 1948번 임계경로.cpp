#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

queue<pii> que;
queue<int> ansque;
vector<pii> edge[10000 + 1];
vector<int> parents[10000 + 1];
int value[10000 + 1], level[10000 + 1];
int ans, st, ed, N, M;
bool visited[10000 + 1][10000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, dist; cin >> from >> to >> dist;
		edge[from].push_back({ to,dist });
		level[to]++;
	}
	cin >> st >> ed;
	que.push({ st , 0});
	while (!que.empty()) {
		auto [now, tmpdist] = que.front();
		que.pop();
		for (auto nxt : edge[now]) {
			auto [nxtpos, cost] = nxt;
			if (value[nxtpos] <= value[now] + cost) {
				if(value[nxtpos] < value[now]+ cost)parents[nxtpos].clear();
				parents[nxtpos].push_back(now);
				value[nxtpos] = value[now] + cost;
			}
			if (--level[nxtpos] == 0) {
				que.push({ nxtpos,value[nxtpos] });
			}
		}
	}

	ansque.push(ed);
	while (!ansque.empty()) {
		int now = ansque.front();
		ansque.pop();
		for (auto nxt : parents[now]) {
			if (!visited[now][nxt]) {
				visited[now][nxt] = 1;
				ansque.push(nxt);
				ans++;
			}
		}
	}
	cout << value[ed] <<"\n";
	cout << ans << "\n";
	return 0;
}