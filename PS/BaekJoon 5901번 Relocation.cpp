#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

vector<int> cycle;
vector<pii> edge[10000 + 1];

int N, M, K;
int dist[10000 + 1][5+1];

void Dijkstra(int st, int cnt) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,st });
	dist[st][cnt] = 0;
	while (!pq.empty()) {
		auto [length, now] = pq.top();
		pq.pop();
		for (const auto& nxt : edge[now]) {
			auto [tmplength, nxtpos] = nxt;
			if (dist[nxtpos][cnt] > length + tmplength) {
				pq.push({ length + tmplength,nxtpos });
				dist[nxtpos][cnt] = length + tmplength;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	cycle.resize(K);
	for (int i = 0; i < K; i++) cin >> cycle[i];

	for (int i = 0; i < M; i++) {
		int st, ed, length; cin >> st >> ed >> length;
		edge[st].push_back({ length,ed });
		edge[ed].push_back({ length,st });
	}
	for (int i = 0; i < K; i++) for (int j = 1; j <= N; j++) dist[j][i] = INF; // 초기화
	for(int i = 0 ; i <K;i++) Dijkstra(cycle[i],i); //cycle을 시작으로 하는 최단 경로 파악
	vector<int> vec;
	for (int i = 0; i < K; i++) vec.push_back(i);
	int ans = INF;
	do {
		int nowlength = 0;
		for (int i = 0; i < K - 1; i++) 
			nowlength += dist[cycle[vec[i + 1]]][vec[i]];
		for (int i = 1; i <= N; i++) {
			bool flag = false;
			for (const auto& now : cycle) if (now == i) flag = true;
			if (flag) continue;
			else ans = min(ans, nowlength + dist[i][vec[0]] + dist[i][vec[K - 1]]);
		}
	} while (next_permutation(vec.begin(), vec.end()));
	
	cout << ans << "\n";
	
	return 0;
}