#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int R, C;
char arr[20 + 5][20 + 5];
bool visited[20 + 1][20 + 1][2];
vector<string> ans;
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> arr[i][j];		
}

bool possible(int y, int x) {
	if (arr[y][x] != '#' && y >= 0 && y < R && x >= 0 && x < C) return true;
	else return false;
}

void sol(int y, int x, int opt) {
	string s = "";
	if (opt == 1) {
		while (possible(y, x)) {
			s.push_back(arr[y][x]);
			visited[y][x][1] = true;
			x++;
		}
	}
	else {
		while (possible(y, x)) {
			s.push_back(arr[y][x]);
			visited[y][x][0] = true;
			y++;
		}
	}
	if(s.length()>=2)ans.push_back(s);
}

void solution() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j][0]) sol (i, j, 0);
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j][1])sol(i, j, 1);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	sort(ans.begin(), ans.end());
	//for (auto a : ans)
	//	cout << a << " ";
	cout << ans[0];
	return 0;
}