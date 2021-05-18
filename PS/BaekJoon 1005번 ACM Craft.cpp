#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
vector<int> edge[1000 + 1];
int level[1000 + 1];
int cost[1000 + 1];
int value[1000 + 1];
int N, K;
void init() {
	cin >> N >> K;
	memset(level, 0, sizeof level);
	memset(cost, 0, sizeof cost);
	memset(value, 0, sizeof value);
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		value[i] = cost[i];
	}
	for (int i = 0; i <= 1000; i++)edge[i].clear();
	for (int i = 0; i < K; i++) {
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
		level[to]++;
	}
}

void solution() {
	queue<pii> que;
	for (int i = 1; i <= N; i++) if (level[i] == 0) que.push({ i,cost[i] });
	while (!que.empty()) {
		auto [now, tmpvalue] = que.front();
		que.pop();
		for (auto nxt : edge[now]) {
			value[nxt] = max(value[nxt], tmpvalue + cost[nxt]);
			if (--level[nxt] == 0) que.push({ nxt,value[nxt] });
		}
	}
	int W; cin >> W;
	cout << value[W] <<"\n";
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		init();
		solution();
	}
	return 0;
}