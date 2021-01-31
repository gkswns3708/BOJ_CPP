#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF LLONG_MIN
int arr[800 + 1][800 + 1];
ll dp[800 + 1][800 + 1];
ll presum[800 + 1][800 + 1];
int N;
ll ans;
int cnt = 0;


void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i * 2- 1; j += 2) {
			int level = -1;
			ll tempvalue =0;
			while (i + level++ < N) {
				int nowlevel = i + level;
				ll lastlevel = presum[i + level][j + level * 2] - presum[i + level][j - 1];
				tempvalue += lastlevel;
				ans = max(ans, tempvalue);
			}
		}
	}
	for (int i = N; i >= 2; i--) {
		for (int j = 2; j <= i * 2 -1; j += 2) {
			int level = 1;
			ll tempvalue = 0;
			int coun = 0;
			while (i + (level--) >= 3) {
				if (j + level * 2 < 1 || j > (i + level) * 2 - 1) break;
				int nowlevel = i + level;
				ll lastlevel =  presum[i + level][j] - presum[i + level][j + level * 2-1];
				tempvalue += lastlevel;
				ans = max(ans, tempvalue);
			}
		}
	}
	cout << ++cnt << ". " << ans << "\n";
}

void input() {
	while (cin >> N && N != 0) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		memset(presum, 0, sizeof(presum));
		ans = -INF;
		for (int i = 1; i <= N; i++) for (int j = 1; j <= i * 2 - 1; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
		for (int i = 1; i <= N; i++) {
			presum[i][1] = arr[i][1];
			for (int j = 2; j <= i * 2 - 1; j++) presum[i][j] = presum[i][j - 1] +   arr[i][j];
		}
		solution();
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	return 0;
}	