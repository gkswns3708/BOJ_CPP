#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#define pii pair<int,int>
#define int long long int
using namespace std;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC; cin >> TC;
	while (TC--) {
		int N, M, W; cin >> N >> M >> W;
		vector<vector<pii>> edge(N + 1);
		vector<int> dist(N + 1, INF);
		dist[1] = 0;

		for (int i = 0; i < M; i++) {
			int from, to, cost; cin >> from >> to >> cost;
			edge[from].push_back({ to,cost });
			edge[to].push_back({ from,cost });
		}
		for (int i = 0; i < W; i++) {
			int from, to, cost; cin >> from >> to >> cost;
			edge[from].push_back({ to,-cost });
		}

		bool flag = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto now : edge[j]) {
					auto [nxt, cost] = now;
					if (dist[nxt] > dist[j] + cost) {
						dist[nxt] = dist[j] + cost;
						if (i == N) flag = true;
					}
				}
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}