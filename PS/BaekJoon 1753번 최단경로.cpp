#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

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

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int V, E,st;
vector<pii> edge[20000 + 1];
vector<int> dist;

void input() {
	cin >> V >> E>>st;
	for (int i = 0; i < E;i++) {
		int u, v, w; cin >> u >> v >> w;
		edge[u].push_back({ w,v });
	}
}

void solution() {
	dist.resize(V + 1, INT_MAX);
	dist[st] = 0;

	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,st });

	while (!pq.empty()) {
		auto [cost, pos] = pq.top();
		pq.pop();
		if (dist[pos] < cost) continue;
		for (auto now : edge[pos]) {
			auto [nxtcost, nxtpos] = now;
			nxtcost += cost;
			if (dist[nxtpos] > nxtcost) dist[nxtpos] = nxtcost,	pq.push({ nxtcost,nxtpos });
		}
	}
	for (int i = 1; i <= V; i++) dist[i] == INT_MAX ? cout << "INF\n" : cout << dist[i] << "\n";
}

int main() {
	fastio;
	input();
	solution();
}