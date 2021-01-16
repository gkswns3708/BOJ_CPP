#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M;
vector<int> vec;
int arr[1001][1001];
int divide[1001][1001];
bool visited[1001][1001];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool possible(int y, int x) {
	if (visited[y][x] != true && arr[y][x] == 1 && y >= 0 && y < N && x >= 0 && x < M) return true;
	else return false;
}
bool npossible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) return true;
	else return false;
}

void BFS(int y, int x,int cnt) {
	queue<pair<int, int>> que;
	que.push({ y,x });
	visited[y][x] = true;
	divide[y][x] = cnt;
	int area = 1;
	while (!que.empty()) {
		auto [ny, nx] = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nny = ny + dy[i];
			int nnx = nx + dx[i];
			if (possible(nny, nnx)) {
				que.push({ nny,nnx });
				visited[nny][nnx] = true;
				divide[nny][nnx] = cnt;
				area++;
			}
		}
	}
	vec.push_back(area);
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	vec.push_back(0);
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				BFS(i, j, cnt++);
			}
		}
	}
	int ans = 0;
	for (auto a : vec)
		ans = max(a, ans);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				int temp = 1;
				vector<int> use;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (npossible(ny, nx)) {
						bool flag = true;
						for (auto a : use) {
							if (divide[ny][nx] == a) {
								flag = false;
								break;
							}
						}
						if (flag) {
							temp += vec[divide[ny][nx]];
							use.push_back(divide[ny][nx]);
						}
					}
				}
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;

	return 0;
}