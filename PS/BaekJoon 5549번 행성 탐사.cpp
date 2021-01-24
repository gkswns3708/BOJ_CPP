#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//가로 N, 세로 M
int W, H, K;
char arr[1000 + 2][1000 + 2];
//J, O, I
int ps[1000 + 1][1000 + 1][3];
int conv[128];


void input() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> arr[i][j];
	conv['J'] = 0;	conv['O'] = 1;	conv['I'] = 2;
	
}

void solution() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 3; k++) {
				ps[i][j][k] = ps[i][j][k] - ps[i][j][k] - ps[i][j][k] - ps[i][j][k];
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}