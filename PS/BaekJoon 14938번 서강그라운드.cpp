#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int value[100 + 1];
int dist[100 + 1][100 + 1];
bool visited[100 + 1];
int N, M, R;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	auto input = [&]()->void {
		cin >> N >> M >> R;
		for (int i = 1; i <= N; i++) cin >> value[i];
		for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) if (i != j) dist[i][j] = INF;
		for (int i = 0; i < R; i++) {
			int a, b, l; cin >> a >> b >> l;
			dist[a][b] = l;
			dist[b][a] = l;
		}
	};
	auto Floyd_washall = [&]()->void {
		for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) 
	   if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
			   dist[i][j] = dist[i][k] + dist[k][j];

	};

	auto makeans = [&]()->int {
		int ans = 0;
		for (int st = 1; st <= N; st++) {
			int sum = 0;
			for (int i = 1; i <= N; i++) if (dist[st][i] <= M) sum +=value[i];
			ans = max(ans, sum);
		}
		return ans;
	};
	
	input();
	Floyd_washall();
	cout << makeans();
	return 0;
}