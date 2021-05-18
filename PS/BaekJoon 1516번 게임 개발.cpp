#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int cost[500 + 1];
int level[500 + 1];
int value[500 + 1];
vector<int> edge[500 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		value[i] = cost[i];
		int num;
		while (cin >> num && num != -1) {
			edge[num].push_back(i);
			level[i]++;
		}
	}

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
	for (int i = 1; i <= N; i++) cout << value[i] << "\n";

	return 0;
}