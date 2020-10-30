#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF (int)1e9
int N;
int arr[100 + 1][10 + 1][1 << 10 + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		arr[1][i][1 << i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j == 0) {
					arr[i][0][k | 1 << 0] += arr[i - 1][1][k];
					arr[i][0][k | 1 << 0] %= INF;
				}
				else if (j == 9) {
					arr[i][9][k | 1 << 9] += arr[i - 1][8][k];
					arr[i][9][k | 1 << 9] %= INF;
				}
				else {
					arr[i][j][k | 1 << j] += arr[i - 1][j - 1][k];
					arr[i][j][k | 1 << j] %= INF;
					arr[i][j][k | 1 << j] += arr[i - 1][j + 1][k];
					arr[i][j][k | 1 << j] %= INF;
				}
			}
		}
	}
	int ans = 0;
	for (int i= 0; i <= 9; i++)
		ans = (ans + arr[N][i][1023]) % INF;

	cout << ans;
	return 0;
}