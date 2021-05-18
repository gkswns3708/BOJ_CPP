#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<int> edge[123 + 1];
queue<int> que;
int level[123], cost[123], value[123],ans;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),	cout.tie(0);
	string s;
	memset(level, -1, sizeof level);
	while (getline(cin, s)) {
		stringstream ss(s);
		char now; int value; string nxts = "";
		ss >> now >> value >> nxts;
		cost[now] = value,level[now] = nxts.size();
		for (auto nxt : nxts) edge[nxt].push_back(now);
	}
	for (int i = 'A'; i <= 'Z'; i++) if (level[i] == 0)value[i] = cost[i], que.push(i);
	while (!que.empty()) {
		auto now= que.front();que.pop();
		ans = max(ans, value[now]);
		for (auto nxt : edge[now]) {
			value[nxt] = max(value[nxt], value[now] + cost[nxt]);
			if (--level[nxt] == 0) que.push( nxt );
		}
	}
	cout << ans;
	return 0;
}