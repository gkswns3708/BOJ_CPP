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

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N, M;
vector<pll> edge[100 + 1];
vector<ll> dist(100+1);
vector<ll> previous(100 + 1);
vector<ll> rev[100 + 1];
bool visited[100 + 1];
bool cycle;


void bellman_ford() {
	for (int k = 0; k < N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				auto [nw, ndist] = edge[i][j];
				if (dist[i] != -INF && dist[nw] < dist[i] + ndist) {
					dist[nw] = dist[i] + ndist;
					previous[nw] = i;
					if (k == N - 1 && visited[nw]) cycle = 1;
				}
			}
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll u, v, w; cin >> u >> v >> w;
		edge[u].push_back({ v,w });
		rev[v].push_back(u);
	}
}

void solution() {
	fill(dist.begin(), dist.end(), -INF);
	dist[1] = 0;

	queue<int> que;
	que.push(N);
	visited[N] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto nw : rev[now]) {
			if (!visited[nw]) {
				visited[nw] = 1;
				que.push(nw);
			}
		}
	}

	bellman_ford();

	if (cycle) cout << -1;
	else {
		vector<int> ans;
		int pos = N;
		while(pos != 1) {
			ans.push_back(pos);
			pos = previous[pos];
		}
		ans.push_back(1);
		for (vector<int>::reverse_iterator riterpos = ans.rbegin(); riterpos != ans.rend(); riterpos++)
			cout << *riterpos << " ";
	}
}

int main() {
	fastio;
	input();
	solution();
}