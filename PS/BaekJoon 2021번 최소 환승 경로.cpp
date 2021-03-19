#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long int
#define pii pair<int,int>
using namespace std;

int N, L;

vector<pair<int, int>> edge[200000 + 1];
vector<int> dist(100000 + 100000 + 2, -1);

int sol(int st, int ed) {
	if (st == ed) return 0;
	queue<int> que;
	dist[st] = 0;
	que.push(st);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto [nxt, cost] : edge[now]) {
			if (dist[nxt] != -1) continue;
			else {
				dist[nxt] = dist[now] + cost;
				que.push(nxt);
			}
		}
	}
	if (dist[ed] == -1) return -1;
	else return dist[ed] - 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	for (int i = 1; i <= L; i++) {
		int now;
		while (cin >> now && now != -1) {
			edge[N + i].push_back({ now,0 });
			edge[now].push_back({ N + i,1 });
		}
	}
	int st, ed; cin >> st >> ed;
	cout << sol(st, ed);
	return 0;
}