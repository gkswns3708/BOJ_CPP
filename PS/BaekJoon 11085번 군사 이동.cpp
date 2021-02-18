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
using tiii = tuple<int, int, int>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int p, w;
int c, v;
int parents[50000 + 1];
vector<tiii> edge;

int _Find(int x) {
	return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
	a = _Find(a), b = _Find(b);
	a < b ? parents[b] = a : parents[a] = b;
}

int main() {
	fastio;
	cin >> p >> w >> c >> v;
	edge.resize(w);
	for (int i = 1; i <= p; i++) parents[i] = i;
	for (int i = 0; i < w; i++) {
		int from, to, width; cin >> from >> to >> width;
		edge[i] = { width,from,to };
	}
	sort(edge.begin(), edge.end(),greater<tiii>());
	for (int i = 0; i < w; i++) {
		auto [width, from, to] = edge[i];
		from = _Find(from), to = _Find(to);
		if (from != to) _Union(from, to);
		if (_Find(c) == _Find(v)) {
			cout << width << "\n";
			break;
		}
	}
	return 0;
}