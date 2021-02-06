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
ll parent[100 + 1];
vector<pll> edge[100 + 1];
vector<ll> rev[100 + 1];
ll dist[100 + 1];
int previous[100 + 1];
bool visited[100 + 1];
bool cycle;


void bellman_ford() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				auto [to, ndist] = edge[i][j];
				if (dist[i] != INF && dist[to] > dist[i] + ndist) {
					dist[to] = dist[i] + ndist;
					previous[to] = i;
					if (k == N && visited[to])
						cycle = 1;
				}
			}
		}
	}
}


void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll u, v, w; cin >> u >> v >> w;
		//*-1해서 넣음 이유 찾기.
		edge[u].push_back({ v,-w });
		rev[v].push_back(u);
	}
}



void solution() {
	queue<int> que;
	que.push(N);
	visited[N] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto nxt : rev[now]) {
			if (!visited[nxt]) {
				visited[nxt] = 1;
				que.push(nxt);
			}
		}
	}

	for (int i = 2; i <= N; i++)
		dist[i] = INF;
	
	bellman_ford();

	if (cycle) cout << -1 << "\n";
	else {
		vector<int> ans;
		int idx = N;
		while (idx != 1) {
			ans.push_back(idx);
			idx = previous[idx];			
		}
		cout << 1 << " ";
		for (vector<int>::reverse_iterator riterpos = ans.rbegin(); riterpos != ans.rend(); riterpos++) cout << *riterpos << " ";
	}
}


int main() {
	fastio;
	input();
	solution();
}