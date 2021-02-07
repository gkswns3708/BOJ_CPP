#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define INF 987654321
#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tiii = tuple<int, int, int >;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

vector<tuple<int, int, int>> edge[100 + 1];
int dist[100 + 1][10000 + 1];
int N, M, K;

void solution() {
	dist[1][0] = 0;
	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
	pq.push({ 0,1,0 });
	while (!pq.empty()) {
		auto [ndist, now, cost] = pq.top();
		pq.pop();
		if (dist[now][cost] < ndist) continue;
		for (auto nxtnode : edge[now]){
			auto [next, next_cost, next_weight] = nxtnode;
			if (cost + next_cost <= M) {
				if (dist[next][cost + next_cost] > dist[now][cost] + next_weight) {
					dist[next][cost + next_cost] = dist[now][cost] + next_weight;
					pq.push({ dist[next][cost + next_cost], next,cost + next_cost });
				}
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= M; i++) ans = min(ans, dist[N][i]);
	ans == INF ? cout << "Poor KCM\n" : cout << ans << "\n";

}


void input() {
	int TC; cin >> TC;
	while (TC--) {
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) {
			edge[i].clear();
			for (int j = 1; j <= M; j++) {
				dist[i][j] = INF;
			}
		}

		for (int i = 0; i < K; i++) {
			int u, v, c, d; cin >> u >> v >> c >> d;
			edge[u].push_back({ v,c,d });
		}
		solution();
	}
}

int main() {
	fastio;
	input();
}