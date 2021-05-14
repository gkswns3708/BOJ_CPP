#include <bits/stdc++.h>
using namespace std;

char arr[10 + 1][10 + 1];
int N, M, K;
unordered_map<string, int> ump;
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
string temp;
void DFS(int y, int x) {
	ump[temp]++;
	if (temp.length() >= 5) return;
	else for (int i = 0; i < 8; i++) {
		int ny = (y + dy[i] + N) % N, nx = (x + dx[i] + M) % M;
		temp.push_back(arr[ny][nx]), DFS(ny, nx), temp.pop_back();
	}
}

int32_t main() {
	 cin >> N >> M >>K;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
	for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) temp.clear(),temp += arr[y][x],	DFS(y, x);
	for (int i = 0; i < K; i++) {
		string s; cin >> s;
		cout << ump[s] << "\n";
	}
	return 0;
}