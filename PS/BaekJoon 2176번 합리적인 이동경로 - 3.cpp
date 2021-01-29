#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define X first
#define Y second
#define INF 987654321

vector<pair<int, int>> edge[1000 + 1];
int dist[1000 + 1];
int dp[1000 + 1];
int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, dis; cin >> from >> to >> dis;
		edge[from].push_back({ to,dis });
		edge[to].push_back({ from,dis });
	}
	fill(dist + 1, dist + N + 1, INF);
	dist[2] = 0; dp[2] = 1;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,2 });
	while (!pq.empty()) {
		int h = pq.top().Y;
		int dis = -pq.top().X;
		pq.pop();
		if (dist[h] ^ dis) continue;
		for (auto it : edge[h]) {
			int tdis = dis + it.Y;
			if (tdis < dist[it.X]) dist[it.X] = tdis, pq.push({ -tdis,it.X });
			if (dist[it.X] < dis) dp[h] += dp[it.X];
		}
	}
	cout << dp[1];
	return 0;
}