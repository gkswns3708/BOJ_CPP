#include <bits/stdc++.h>
#define int long long int
using namespace std;
int N, M;
char arr[1010][30];
bool visited[1010][30];


int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool possible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M && !visited[y][x]) return true;
	else return false;
}

int BFS(int x) {
	int ans = 987654321;
	memset(visited, 0, sizeof(visited));
	priority_queue<tuple<int, int, int>> que;
	que.push({ 0,x,0 });
	visited[0][x] = 1;
	while (!que.empty()) {
		auto [dist,y, x] = que.top();
		que.pop();
		if (y == N - 1) {
			ans = min(ans, dist);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 987654321;
	for (int i = 0; i < N; i++) {
		if (arr[i][0] == 'c') {
			ans = min(ans, BFS(i));
		}
	}
}