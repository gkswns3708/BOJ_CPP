#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int dist[500 + 1];
vector<pii> edge[500 + 1];

void init() {
	for (int i = 0; i <= 500; i++) for (int j = 0; j <= 500; j++) {
		edge[i].clear();
		if (i == 1) dist[i] = 0;
		else dist[i] = INF;
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		init();
		int N, M, W; cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int from, to, dist; cin >> from >> to >> dist;
			edge[from].push_back({ to,dist });
			edge[to].push_back({ from,dist });
		}
		for (int i = 0; i <  W; i++) {
			int from, to, dist; cin >> from >> to >> dist;
			edge[from].push_back({ to,-dist });
		}
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (const auto& now : edge[j]) {
					auto [nxt, length] = now;
					if (dist[nxt] > dist[j] + length) {
						dist[nxt] = dist[j] + length;
						if (i == N) flag = true;
					}
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}