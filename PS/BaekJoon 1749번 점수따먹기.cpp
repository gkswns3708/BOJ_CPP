#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int arr[200][200];
ll sum[201][201];
int N, M;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) cin >> arr[i][j];
}

ll solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + arr[i][j];
		}
	}
	ll MAX = LLONG_MIN;
	for (int y1 = 1; y1 <= N; y1++) {
		for (int x1 = 1; x1 <= M; x1++) {
			for (int y2 = y1; y2 <= N; y2++) {
				for (int x2 = x1; x2 <= M; x2++) {
					MAX = max(MAX, sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1]);
				}
			}
		}
	}
	return MAX;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	cout << solution();
	return 0;
}