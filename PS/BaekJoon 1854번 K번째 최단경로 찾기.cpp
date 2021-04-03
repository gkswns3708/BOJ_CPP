#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
#define int long long int
using namespace std;

int N, M, K;
vector <pair<int, int>> edge[1000+1];
priority_queue<int> dist[1000 + 1];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[1].push(0);
	pq.push({ 0,1 });
	while (!pq.empty()) {
		auto [cost, pos] = pq.top();
		pq.pop();

		for (auto now : edge[pos]) {
			auto [nxtcost, nxt] = now;
			if (dist[nxt].size() < K) dist[nxt].push(cost + nxtcost), pq.push({ cost + nxtcost, nxt });
			else if (nxtcost + cost < dist[nxt].top()) {
				dist[nxt].pop();
				dist[nxt].push(nxtcost + cost);
				pq.push({ nxtcost + cost,nxt });
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c,b });
	}

	dijkstra();

	for (int i = 1; i <= N; i++) dist[i].size() == K ? cout << dist[i].top() << "\n" : cout << -1<<"\n";
	
	return 0;
}