#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char s[26];
bool visited[7][7],vis[7][7];
int ans = 0;
vector<int> vec;

bool dfs2() {
	queue<int> que;
	que.push(vec[0]);
	vis[vec[0] / 5][vec[0] % 5] = 1;
	int cnt = 1;
	while (!que.empty()) {
		int nowpos = que.front();
		int y = nowpos / 5;
		int x = nowpos % 5;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + "1210"[i] - '1';
			int nx = x + "2101"[i] - '1';
			if (nx >= 0 && ny >= 0 && nx <= 5 && ny <= 5) {
				if (visited[ny][nx] && !vis[ny][nx]) {
					vis[ny][nx] = 1;
					que.push(ny * 5 + nx);
					cnt++;
				}
			}
		}
	}
	if (cnt == 7) return true;
	return false;
}

bool possible() {
	memset(visited, 0, sizeof(visited));	
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (auto a : vec) {
		if (s[a] == 'S') cnt++;
		visited[a/5][a%5] = 1;
	}
	if (cnt < 4) return false;
	return dfs2();
}

void DFS(int cnt,int pos){
	if (cnt == 7) {
		ans += (int)possible();
		return;
	}
	for (int i = pos; i < 25; i++) {
		vec.push_back(i);
		DFS(cnt + 1, i+1);
		vec.pop_back();
	}
}

int main() {
	fastio;
	for (int i = 0; i < 25; i++) cin >> s[i];
	DFS(0, 0);
	cout << ans << "\n";
}