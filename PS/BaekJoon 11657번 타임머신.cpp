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
using tiii = tuple<int, int, int>;
using tlll = tuple<ll, ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N, M;
vector<ll> dist;
vector<tlll> edge;

void input() {
	cin >> N >> M;
	dist.resize(N + 1, INF);
	for (int i = 0; i < M; i++) {
		int from, to, dist; cin >> from >> to >> dist;
		edge.push_back({ from,to,dist });
	}
}

void solution() {
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (auto now : edge) {
			auto [from, to, cost] = now;
			if (dist[from] == INF) continue;

			if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
	}

	for (auto now : edge) {
		auto [from, to, cost] = now;
		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout << "-1\n";
			return;
		}
	}

	for (int i = 2; i <= N; i++) {
		dist[i] == INF ? cout << "-1\n" : cout << dist[i] << "\n";
	}
}

int main() {
	fastio;
	input();
	solution();
}