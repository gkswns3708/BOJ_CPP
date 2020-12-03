#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int arr[760][760];
int D[760][760][4];// 우상을 기준으로 시계방향
int R, C;

bool possible(int y, int x) {
	if (y >= 0 && y < R && x >= 0 && x < C) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s; cin >> s;
		for (int j = 0; j < C; j++)
			arr[i][j] = s[j] - '0';
	}
	for (int d = 0; d < 2; d++) {
		if (d == 0) {
			for (int i = 0; i < R + C - 2; i++) {
				for (int j = 0; j < C; j++) {
					int r = i - j;
					if (possible(r, j))
						continue;
					if (possible(r + 1, j - 1))
						D[r][j][d] = arr[r][j];
					else
						D[r][j][d] = arr[r][j] * (D[r + 1][j - 1][d] + 1);
				}
			}
		}
	}

	return 0;
}