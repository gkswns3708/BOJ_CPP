#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
int N, M,ans;
int arr[500 + 1][500 + 1];
bool visited[500 + 1][500 + 1];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
vector<pii> pos;
vector<pii> vec = { {0,0},{0,-1},{0,1},{1,0},
					{0,0},{0,-1},{-1,0},{0,1},
					{0,0},{-1,0},{0,-1},{1,0},
					{0,0},{-1,0},{0,1},{1,0}};

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
}

bool possible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M&& !visited[y][x]) return true;
	else return false;
}

void DFS(int y, int x, int depth,int value) {
	if (depth == 3) ans = max(value + arr[y][x], ans);
	
	else {
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i],nx = x + dx[i];
			if (possible(ny, nx)) {
				pos.push_back({ y,x });
				visited[ny][nx] = 1;
				DFS(ny, nx, depth + 1, value + arr[y][x]);
				pos.pop_back();
				visited[ny][nx] = 0;
			}
		}
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			DFS(i, j, 0, 0);
			visited[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				bool flag = 1;
				int sum = 0;
				for (int p = 0; p < 4; p++) {
					auto [tmpdy,tmpdx] = vec[k * 4 + p];
					int ny = i + tmpdy, nx = j + tmpdx;
					if (possible(ny, nx))sum += arr[ny][nx];
					else flag = false;
				}
				if (flag) ans = max(ans, sum);	
			}
		}
	}
}

void printans() {
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	solution();
	printans();
	return 0;
}