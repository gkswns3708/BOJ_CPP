#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int K, H, W;
int arr[200 + 1][200 + 1];
bool visited[200 + 1][200 + 1][30+1];


bool possible(int y, int x, int k) {
	return visited[y][x][k] == false && y >= 0 && y < H&& x >= 0 && x < W&& k <= K && arr[y][x] != 1;
}

void input() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> arr[i][j];
}

void solution() {
	int ans = 0;
	bool check = false;
	queue<tuple<int, int, int>> que;
	que.push({ 0,0,0 });
	visited[0][0][0] = true;
	while (!que.empty()) {
		int size = que.size();
		for (int n = 0; n < size; n++) {
			auto [y, x, k] = que.front();
			if (y == H - 1 && x == W - 1) check = true;
			if (check) break;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + "1012"[i] - '1';
				int ny = y + "2101"[i] - '1';
				if (possible(ny, nx, k)) {
					que.push({ ny,nx,k });
					visited[ny][nx][k] = true;
				}
			}
			for (int i = 0; i < 8; i++) {
				int nx = x + "10013443"[i] - '2';
				int ny = y + "01344310"[i] - '2';
				if (possible( ny,nx,k+1)) {
					que.push({ ny, nx, k+1 });
					visited[ny][nx][k + 1] = true;
				}

			}
		}
		if (check) break;
		ans++;
	}
	if (check) cout << ans;
	else cout << -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}