#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define INF 987654321
#define ll long long

ll sum;
int N, M;
int ans = 0;
int arr[1000 + 1][1000 + 1];
int colvalue[1000 + 1];
int rowvalue[1000 + 1];
int gap = -INF;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
	for (int i = 0; i < N; i++) {
		rowvalue[i] = arr[i][0];
		for (int j = 1; j < M - 1; j++) rowvalue[i] += arr[i][j]*2;
		rowvalue[i] += arr[i][M - 1];
		if (i == 0 || i == N - 1) continue;
		else rowvalue[i] *= 2;
	}
	for (int j = 0; j < M; j++) {
		colvalue[j] = arr[0][j];
		for (int i = 1; i < N - 1; i++) colvalue[j] += arr[i][j] * 2;
		colvalue[j] += arr[N-1][j];
		if (j == 0 || j == M - 1) continue;
		else colvalue[j] *= 2;		
	}
	for (int i = 0; i < N; i++) sum += rowvalue[i];
}
void solution() {
	for (int TC = 0; TC < 2; TC++) {

		int tempswitch;
		if (TC) tempswitch = rowvalue[N - 1];
		else tempswitch = rowvalue[0];
		for (int i = 1; i < N-1; i++) {
			int nowgap = (tempswitch * 2 + rowvalue[i]/2) - (tempswitch + rowvalue[i]);
			gap = max(gap, nowgap);
		}
	}
	for (int TC = 0; TC < 2; TC++) {
		int tempswitch;
		if (TC) tempswitch = colvalue[M - 1];
		else tempswitch = colvalue[0];
		//행 차이 최대값.
		for (int i = 1; i < M - 1; i++) {
			int nowgap = (tempswitch * 2 + colvalue[i]/2) - (tempswitch + colvalue[i]);
			gap = max(gap, nowgap);
		}
	}
	if (gap < 0) cout << sum;
	else cout << sum + gap;
}

int main() {
	fastio;
	input();
	solution();
}