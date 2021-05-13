#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int dist[100 + 1][100 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	memset(dist, INF, sizeof dist);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) 
	if (i == j)dist[i][j] = 0;else dist[i][j] = INF;
		
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}
	for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) 
	if (dist[i][k] != -1 && dist[k][j] != -1) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			
	tiii ans = { INF,-1,-1 };
	for (int f = 1; f <= N; f++) {
		for (int s = f + 1; s <= N; s++) {
			int sum = 0;
			for (int i = 1; i <= N; i++) sum += min(dist[f][i], dist[s][i]);
			auto& [tempsum, tempf, temps] = ans;
			if (tempsum > sum) 	tempsum = sum,tempf = f,temps = s;
		}
	}
	
	auto [anssum, ansf, anss] = ans;
	cout << ansf << " " << anss << " " << anssum * 2;
	
	return 0;
}