#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define INF 987654321
using namespace std;

int N, M;
vector<pii> Keypos;
int dist[251][251];
int parents[251];
map<pii, int> mppos;
string arr[55];
int ans = 0;
int _Find(int x) {
	return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
	a = _Find(a), b = _Find(b);
	a < b ? parents[b] = a : parents[a] = b;
}

void Cal_dist(pii param) {
	bool visited[51][51] = { 0, };
	queue<pii> que;
	que.push(param);
	visited[param.first][param.second] = 1;
	auto possible = [&](int y, int x) -> bool {
		if (y < N && y >= 0 && x < N && x >= 0 && arr[y][x] != '1' && !visited[y][x]) return true;
		else return false;
	};
	int dt= 0;
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			auto [y,x] = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + "1210"[i] - '1';
				int nx = x + "2101"[i] - '1';
				if (possible(ny, nx)) {
					visited[ny][nx] = 1;
					if (arr[ny][nx] == 'K' || arr[ny][nx] == 'S') {
						int st = mppos[param];
						int ed = mppos[{ny, nx}]; 
						dist[st][ed] = dt+1;
					}
					que.push({ ny,nx });
				}
			}
		}
		dt++;
	}
}

int32_t main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'K' || arr[i][j] == 'S') {
				Keypos.push_back({ i,j });
				mppos[{i, j}] = Keypos.size()-1;
			}
		}
	}
	for (int i = 0; i < M + 1; i++)
		for (int j = 0; j < M + 1; j++)
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		
	
	for (const auto& now: Keypos) Cal_dist(now);

	for (int i = 0; i < Keypos.size(); i++) parents[i] = i;
	vector<tiii> vec;
	for (int i = 0; i < Keypos.size(); i++) 
		for (int j = i + 1; j < Keypos.size(); j++) 
			vec.push_back({ dist[i][j],i,j });

	sort(vec.begin(), vec.end());
	int cnt = 0;
	for (const auto& now : vec) {
		auto [nowdist, st, ed] = now;
		if (_Find(st) != _Find(ed)) {
			_Union(st, ed);
			if (nowdist == INF) {
				cout << -1 << "\n";
				exit(0);
			}
			ans += nowdist;
			if (++cnt == Keypos.size() - 1)break;
		}
	}

	cout << ans;

	return 0;
}