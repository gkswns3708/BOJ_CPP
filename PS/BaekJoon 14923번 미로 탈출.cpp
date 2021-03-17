#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long int
using namespace std;

int N, M;
int sx, sy;
int ex, ey;
int arr[1000 + 2][1000 + 2];
bool visited[1000 + 2][1000 + 2][2];

bool possible(int y, int x, int wall) {
	if (y > 0 && y <= N && x > 0 && x <= M && wall >= arr[y][x]  && !visited[y][x][wall]) return true;
	else return false;
}

int BFS() {
	int ans = -1;
	queue<tuple<int, int, int>> que;
	if (arr[sy][sx] == 1) que.push({ sy,sx,0 }),visited[sy][sx][0] = 0;
	else que.push({ sy,sx,1 }), visited[sy][sx][1] = 1;
	int dist = 0;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			auto [y, x, wall] = que.front();
			que.pop();
			if (y == ey && x == ex) return dist;
			for (int i = 0; i < 4; i++) {
				int nx = x + "2101"[i] - '1';
				int ny = y + "1210"[i] - '1';
				if (possible(ny, nx, wall)) {
					if (arr[ny][nx] == 1) que.push({ ny,nx, 0 }),visited[ny][nx][0] = 1;
					else que.push({ ny,nx,wall }),visited[ny][nx][wall] = 1;					
				}
			}
		}
		dist++;
	}
	return -1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> sy >> sx >> ey>>ex;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++) cin >> arr[i][j];
	cout << BFS() << "\n";
	return 0;
}