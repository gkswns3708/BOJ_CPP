#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
#define MOD 1000007
using namespace std;

int arr[50 + 1][50 + 1];
int dp[50 + 1][50 + 1][50 + 1][50+1];
int N, M, C;

int solution(int y, int x, int cnt, int prev) {
	if (y > N || x > M) return 0;
	if (y == N && x == M) {
		if (cnt == 0 && arr[y][x] == 0) return 1;
		if (cnt == 1 && arr[y][x] > prev) return 1;
		return 0;
	}

	int& ret = dp[y][x][cnt][prev];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[y][x] == 0) {
		ret = (solution(y + 1, x, cnt, prev) + solution(y, x + 1, cnt, prev)) % MOD;
	}
	else if (arr[y][x] > prev) {
		ret = (solution(y + 1, x, cnt - 1, arr[y][x]) + solution(y, x + 1, cnt - 1, arr[y][x])) % MOD;
	}

	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> C;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= C; i++) {
		int y, x; cin >> y >> x;
		arr[y][x] = i;
	}
	for (int i = 0; i <= C; i++) cout << solution(1, 1, i, 0) <<" ";
	return 0;
}