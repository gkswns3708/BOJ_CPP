#include<bits/stdc++.h>

using namespace std;
int ar[1000][1000];
bool visit[1000][1000][10 + 1];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M, K;

bool ps(int y, int x, int wall) {
	if (y >= 0 && y < N && x >= 0 && x < M && wall <= K && visit[y][x][wall] != true) return true;
	else return false;
}

int BFS() {
	queue<tuple<int, int, int>> que;
	if (N == 1 && M == 1)return 0;
	que.push({ 0,0,0 });
	visit[0][0][0] = true;
	int dist = 0;
	while (!que.empty()) {
		int size = que.size();
		dist++;
		while (size--) {
			auto [y, x, wl] = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ps(ny, nx, wl + ar[ny][nx])) {
					visit[ny][nx][wl + ar[ny][nx]] = true;
					que.push({ ny,nx,wl + ar[ny][nx] });
					if (ny == N - 1 && nx == M - 1) return dist;
				}
			}
		}

	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			ar[i][j] = s[j] - '0';
		}
	}

	int ans = BFS();
	if (ans != -1) {
		cout << ans + 1 << "\n";
	}
	else cout << -1 << "\n";
	return 0;
}