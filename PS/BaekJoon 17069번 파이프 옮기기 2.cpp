#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N;
int arr[33][33];
ll ans[34][34][3];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)cin >> arr[i][j];
	ans[1][2][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!arr[i][j+1]) {
				ans[i][j + 1][0] += ans[i][j][0] + ans[i][j][1];
			}
			if (!arr[i+1][j]) {
				ans[i + 1][j][2] += ans[i][j][1] + ans[i][j][2];
			}
			if (!arr[i + 1][j + 1] && !arr[i + 1][j] && !arr[i][j + 1]) {
				ans[i + 1][j + 1][1] += ans[i][j][0] + ans[i][j][1] + ans[i][j][2];
			}
		}
	}
	cout << ans[N][N][0] + ans[N][N][1] + ans[N][N][2];

	return 0;
}