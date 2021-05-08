#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int parents[10000 + 1], sz[10000 + 1];

int _Find(int a) {
	return parents[a] == a ? a : parents[a] = _Find(parents[a]);
}

void _Union(int a, int b) {
	a = _Find(a);
	b = _Find(b);
	a < b ? parents[b] = a : parents[a] = b;
}

struct Edge {
	int from, to, value;
	bool operator<(Edge const& a) {
		return value < a.value;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int V, E; cin >> V >> E;

	for (int i = 1; i <= V; i++) parents[i] = i,sz[i] = 1;
	vector<Edge> vec(E);
	for (int i = 0; i < E; i++) {
		int from, to, value; cin >> from >> to >> value;
		vec.push_back({ from,to,value });
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	for (const auto& now : vec) {
		auto [from, to, value] = now;
		if (_Find(from) != _Find(to)) {
			ans += value;
			_Union(from, to);
		}
	}
	cout << ans;
	return 0;
}