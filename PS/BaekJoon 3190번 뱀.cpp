#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int arr[105][105];
int N,K,L;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool poss = true;
deque<tuple<int, int, int>> deq;
deque<pair<int, int>> dirinfo;

bool possible(int y, int x) {
	if (arr[y][x] != 2 && y >= 1 && y <= N && x >= 1 && x <= N) return true;
	else {
		poss = false;
		return false;
	}
}

void move() {
	auto [y, x, dir] = deq.front();
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (possible(ny, nx)) {
		deq.push_front({ ny,nx,dir });
	}
}

int solved() {
	deq.push_back({ 1,1,0 });
	int time = 0;
	while (poss) {
		time++;
		move();
		auto [y, x, dir] = deq.front();
		if (arr[y][x] == 0) {
			auto [ly, lx, dir] = deq.back();
			arr[ly][lx] = 0;
			arr[y][x] = 2;
			deq.pop_back();
		}
		if (!dirinfo.empty() && time == dirinfo.front().first) {
			auto& [y, x, dir] = deq.front();
			if (dirinfo.front().second == 1)
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
			dirinfo.pop_front();
		}
	}
	return time;
}

int main() {
	fastio;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x; cin >> y >> x;
		arr[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time; char dir; cin >> time >> dir;
		if (dir == 'L') dirinfo.push_back({ time,0 });
		else dirinfo.push_back({ time,1 });
	}
	cout << solved();
	return 0;
}
