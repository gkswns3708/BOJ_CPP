#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M;
vector<pair<int,int>> edge[1000 + 1];
int dist[1000 + 1];
int dp[1000 + 1];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
}

void solution() {
	fill(dist+1, dist + N + 1, 0x7fffffff);
	priority_queue<pair<int, int>> pq;
	dist[2] = 0;
	dp[2] = 1;
	pq.push({ 0,2 });
	while (!pq.empty()) {
		int h = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		if (dist[h] ^ dis) continue;
		for (auto now : edge[h]) {
			int nd = now.second + dis;
			if (nd < dist[now.first]) dist[now.first] = nd, pq.push({ -nd,now.first });
			if (dist[now.first] < dis) dp[h] += dp[now.first];
		}
	}
	cout << dp[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}