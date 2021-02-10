#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define INF 987654321
#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N, M,ans = -INF;
int arr[20 + 1][20 + 1];
bool visited[20 + 1][20 + 1];

bool possible(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M && !visited[y][x] ) return true;
	else return false;
}

int BFS(int y, int x) {
	queue<pii> que;
	que.push({ y,x });
	visited[y][x] = true;
	int ans = 1;
	bool check = false;
	while (!que.empty()) {
		auto [ny, nx] = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nny = ny + "1210"[i] - '1';
			int nnx = nx + "2101"[i] - '1';
			if (possible(nny, nnx)) {
				if (arr[nny][nnx] == 2) {
					que.push({ nny,nnx });
					visited[nny][nnx] = 1;
					ans++;
				}
				else if (arr[nny][nnx] == 0) check = true;
				
			}
		}
	}
	if (check) return 0;
	else return ans;
}

void checkpos() {
	memset(visited, 0, sizeof(visited));
	int nowans = 0;
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	if (arr[i][j] == 2 && !visited[i][j])nowans += BFS(i, j);
	ans = max(ans, nowans);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
}
void solution() {
	for (int i = 0; i < N * M-1; i++) {
		for (int j = i + 1; j < N * M; j++) {
			if (arr[i / M][i % M] == 0 && arr[j / M][j % M] == 0) {
				arr[i / M][i % M] = arr[j / M][j % M] = 1;
				checkpos();
				arr[j / M][j % M] = arr[i / M][i % M] = 0;
			}
		}	
	}
	cout << ans;
}

int main() {
	fastio;
	input();
	solution();
}