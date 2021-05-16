#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int arr[200 + 1][200 + 1];
pii virus[200 + 1][200 + 1];
vector<pii> pos[1000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;
	for (int i = 0; i <= 200; i++) for (int j = 0; j <= 200; j++) virus[i][j] = { -1,-1 };
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> arr[i][j];
		pos[arr[i][j]].push_back({ i,j });
		if (arr[i][j] != 0) virus[i][j] = { arr[i][j],0 };
	}
	
	queue<tiii> que;
	for (int i = 1; i <= 1000; i++) {
		if(pos[i].empty()) continue;
		else for (auto now : pos[i]) que.push({ i,now.first,now.second });
	}	

	auto possible = [&](int y, int x)->bool {
		if (y >= 0 && y < N && x >= 0 && x < N && virus[y][x].first == -1) return true;
		else return false;
	};
	 
	int dist = 1;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			auto [num,y,x] = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + "1210"[i] - '1', nx = x + "2101"[i] - '1';
				if (possible(ny, nx)) {
					virus[ny][nx].first = num;
					virus[ny][nx].second = dist;
					que.push({ num,ny,nx });
				}
			}
		}
		dist++;
	}

	int s, y, x; cin >> s >> y >> x;
	if (virus[y - 1][x - 1].second > s) cout << 0;	
	else cout << virus[y - 1][x - 1].first;
	
	return 0;
}