#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int dist[100 + 1][100 + 1];
int sumdist[100 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) if(i!=j)dist[i][j] = INF;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) 
		if (dist[i][k] != INF && dist[k][j] != INF) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int ans = 0, pos = -1;

	//치킨집을 f,s로 했을 때의 최소값.
	int value = INF;
	int first, second;
	for (int f = 1; f <= N; f++) {
		for (int s = f + 1; s <= N; s++) {
			int sum = 0;
			for (int i = 1; i <= N; i++) sum += min(dist[f][i], dist[s][i]);				
			if (sum < value) value = sum,first = f,	second = s;
		}
	}
		
	cout << first << " " << second << " " << value * 2;
		
	return 0;
}