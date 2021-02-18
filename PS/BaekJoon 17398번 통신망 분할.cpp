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

int N, M, Q;
vector<pii> edge;
vector<int> disedge;
bool check[100000 + 1];
int parents[100000 + 1];
ll cost[100000 + 1];
ll total;

int _Find(int x) {
	return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
	a = _Find(a), b = _Find(b);
	if(a != b) a < b ? parents[b] = a,cost[a] += cost[b] : parents[a] = b, cost[b] += cost[a];
}


int main() {
	fastio;
	cin >> N >> M >> Q;
	edge.resize(M);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[i] = { a,b };
	}
	disedge.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> disedge[i];
		check[disedge[i] - 1] = true;
	}

	for (int i = 1; i <= N; i++) cost[i] = 1, parents[i] = i;

	for (int i = 0; i < edge.size(); i++) {
		if (check[i]) continue;
		auto [a, b] = edge[i];
		_Union(a, b);
	}
	for (int i = disedge.size() - 1; i >= 0; i--) {
		int order = disedge[i] - 1;
		auto [a, b] = edge[order];
		a = _Find(a), b = _Find(b);
		if (a != b) {
			total += cost[a] * cost[b];
			_Union(a, b);
		}
	}
	cout << total << "\n";
	return 0;	
}