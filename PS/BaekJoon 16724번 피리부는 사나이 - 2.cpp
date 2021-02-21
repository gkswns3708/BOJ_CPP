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

int N, M;
char arr[1000 + 10][1000 + 10];
int visited[1000 + 10][1000 + 10];
pii pi[26+1];
int alpha[90 + 10];
int cnt,ans;

int dfs(int y, int x) {
	if (visited[y][x] != -1) return visited[y][x];
	visited[y][x] = cnt;
	auto [dy, dx] = pi[alpha[arr[y][x]]];
	return visited[y][x] = dfs(y + dy, x + dx);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) {
		cin >> arr[i][j];
		visited[i][j] = -1;
	}
	alpha['L'] = 'L' - 'A';
	alpha['U'] = 'U' - 'A';
	alpha['D'] = 'D' - 'A';
	alpha['R'] = 'R' - 'A';
	pi[alpha['L']] = { 0,-1 };
	pi[alpha['U']] = { -1,0 };
	pi[alpha['R']] = { 0,1 };
	pi[alpha['D']] = { 1,0 };
}

void solution() {
	set<int> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == -1) {
				cnt++;
				dfs(i, j);
				if (visited[i][j] == cnt) ans++;
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