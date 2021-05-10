#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

char arr[150 + 2][150 + 2];
char board[2+1][50 + 1][50 + 1];
char temp[50 + 1][50 + 1];
int n[3], m[3];

void rotateR() {
	for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) temp[i][j] = '0';
	for (int i = 0; i < n[1]; i++) for (int j = 0; j < m[1]; j++) temp[j][n[1] - 1 - i] = board[1][i][j];
		
	
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	for (int TC = 0; TC < 2; TC++) {
		cin >> n[TC] >> m[TC];
		for (int i = 0; i < n[TC]; i++) for (int j = 0; j < m[TC]; j++) cin >> board[TC][i][j];		
	}

	//arr에 board[0]을 고정함.
	int gap = max(n[1], m[1]);
	for (int y = 0; y < n[0]; y++) for (int x = 0; x < m[0]; x++) arr[y + gap][x + gap] = board[1][y][x];
		
	int ans = INF;
	for (int dir = 0; dir < 4; dir++) {
		for (int sy = 0; sy < n[0] + n[1]; sy++) {
			for (int sx = 0; sx < m[0] + m[1]; sx++) {		

			}
		}
	}
	cout << ans;
	return 0;
}