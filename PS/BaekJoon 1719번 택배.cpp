#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int dist[200 + 1][200 + 1];
int parents[200 + 1][200 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = INF;
	for (int i = 0; i < M; i++) {
		int from, to, dist1; cin >> from >> to >> dist1;
		dist[from][to] = dist1;
		dist[to][from] = dist1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(i == j)	dist[i][j] = 0;
			parents[i][j] = j;
		}
	}
	for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) 	for (int j = 1; j <= N; j++) {
		if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j],parents[i][j] = parents[i][k];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)cout << "- ";
			else cout << parents[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}