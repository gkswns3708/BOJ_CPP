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
char arr[1000 + 1][1000 + 1];
int parents[1000 + 1][1000 + 1];
map<char, pair<int, int>> mp;
int cnt;

int dfs(int y, int x) {
	if (parents[y][x]!= -1) return parents[y][x];
	int ret = parents[y][x];
	parents[y][x] = cnt;
	auto [dy, dx] = mp[arr[y][x]];
	int ny = y + dy;
	int nx = x + dx;
	ret = dfs(ny, nx);
	parents[y][x] = ret;
	return parents[y][x];
}


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> arr[i][j];
		parents[i][j] = -1;
	}
	mp['L'] = { 0,-1 },mp['D'] = { 1,0 },mp['R'] = { 0,1 }, mp['U'] = { -1,0 };	
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (parents[i][j] == -1) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	set<int> s;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			s.insert(parents[i][j]);
	cout << s.size();
}

int main() {
	fastio;
	input();
	solution();
}