#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;


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

int N, M,T;
int arr[100 + 1][100 + 1];
bool visited[100 + 1][100 + 1];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };


bool possible(int y, int x) {
	if (x >= 1 && x <= M && y >= 1 && y <= N && !visited[y][x] && arr[y][x] != 1) return true;
	else return false;
}

void input() {
	cin >> N >> M>>T;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> arr[i][j];
}

void solution() {
	int ans = 987654321;
	queue<pii> que;
	que.push({ 1,1 });
	visited[1][1] = 1;
	int dist = 0;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			auto [y, x] = que.front();
			if (y == N && x == M) ans = min(ans, dist);
			que.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (possible(ny, nx)) {
					if (arr[ny][nx] == 2) ans = min(ans, dist + N - ny + M - nx + 1);
					else que.push({ ny,nx });
					visited[ny][nx] = 1;
				}
			}
		}
		dist++;
	}
	ans > T ? cout << "Fail\n" : cout << ans<<"\n";
}

int main() {
	fastio;
	input();
	solution();
}