#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int N, M;

pii pos[1000 + 1];
int dist[1000 + 1][1000 + 1];
int parents[1000 + 1];

int cal(pii a, pii b) {
	return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
}


int _Find(int a) {
	return parents[a] == a ? a : parents[a] = _Find(parents[a]);rkq
}

void _Union(int a, int b) {
	a = _Find(a);
	b = _Find(b);
	a < b ? parents[b] = a : parents[a] = b;
}

struct Edge {
	int from, to, value;

	bool operator<(const Edge& a) {
		return value < a.value;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x, y; cin >> x >> y;
		pos[i] = { x,y };
		parents[i] = i;
	}
	vector<Edge> vec;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			dist[i][j] = cal(pos[i], pos[j]);
			vec.push_back({ i,j,dist[i][j] });
		}
	}


	sort(vec.begin(), vec.end());

	double ans = 0;
	for (int i = 0; i < M; i++) {
		int from, to; cin >> from >> to;
		ans += sqrt(cal(pos[a], pos[b]));
	}

	for (const auto& now : vec) {
		auto [from, to, value] = now;
		from = _Find(from), to = _Find(to);
		if (from != to) {
			ans += value;
			_Union(from, to);
		}
	}
	cout << fixed;
	cout.precision(2);

	cout << sqrt(ans);


	return 0;
}