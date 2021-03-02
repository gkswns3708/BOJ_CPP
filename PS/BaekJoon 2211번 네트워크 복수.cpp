#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;


int dist[1000 + 1];
int parent[1000 + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	vector<pair<int,int>> Edge[1000 + 1];
	for (int i = 0; i < M; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		Edge[from].push_back({ to,cost }); 
		Edge[to].push_back({ from,cost });
	}
	fill(dist, dist + 1000 + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,1 });
	dist[1] = 0;
	while (!pq.empty()) {
		auto [cost, now] = pq.top();
		pq.pop();
		if (dist[now] < cost) continue;
		for (auto nxt : Edge[now]) {
			auto [nxtpos, nxtcost] = nxt;
			nxtcost += cost;
			if (dist[nxtpos] > nxtcost) {
				dist[nxtpos] = nxtcost;
				pq.push({ nxtcost,nxtpos });
				parent[nxtpos] = now;
			}
		}
	}

	cout << N - 1 << "\n";
	for (int i = 2; i <= N; i++)
		cout << parent[i] << " "<< i << "\n";
	return 0;
}