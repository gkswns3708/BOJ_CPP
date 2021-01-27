#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<int,int>> edge[1000 + 1];
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
	fill(dist + 1, dist + N + 1, 0x7fffffff);
	dist[2] = 0; dp[2] = 1;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,2 });
	//초기조건 생각.
	while (!pq.empty()) {
		//현재까지의 거리
		//현재 노드
		int h = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		if (dist[h] ^ dis) continue;
		for (auto it : edge[h]) {
			int tdis = dis + it.second;
			if (tdis < dist[it.first]) dist[it.first] = tdis, pq.push({-tdis,it.first});
			if (dist[it.first] < dis) dp[h] += dp[it.first];
		}
	}
	cout << dp[1];
	return 0;
}