#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int dist[100 + 1][100 + 1];
int parents[100 + 1][100 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) if (i != j)dist[i][j] = INF;
	for (int i = 0; i < M; i++) {
		int from, to, value; cin >> from >> to >> value;
		dist[from][to] = min(dist[from][to],value);
		if(dist[from][to] == value) parents[from][to] = to;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						parents[i][j] = parents[i][k];
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << dist[i][j] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF || dist[i][j] == 0) {
				cout << "0\n";
				continue;
			}
			vector<int> path;
			int nowpos = i;
			while (1) {
				if (nowpos == j) {
					path.push_back(nowpos);
					break;
				}
				else {
					path.push_back(nowpos);
					nowpos = parents[nowpos][j];
				}
			}
			cout << path.size() << " ";
			for (auto now : path)cout << now << " ";
			cout << "\n";
		}
	}
	return 0;
}