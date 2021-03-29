#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define int long long int
using namespace std;

int len[1000 + 1], dp[1000 + 1][1000 + 1], N, M;

int sol(int col, int cnt) {
	if (cnt == N) return 0;
	int& ret = dp[col][cnt];
	if (ret != -1) return ret;

	int right = M - col + 1;
	ret = sol(len[cnt] + 1, cnt + 1) + right * right;

	if (col + len[cnt] - 1 < M) ret = min(ret, sol(col + len[cnt] + 1, cnt + 1));

	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> len[i];
	memset(dp, -1, sizeof(dp));
	cout << sol(len[0]+1, 1);
	
	return 0;
}