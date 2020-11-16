#include <bits/stdc++.h>
using namespace std;

int f[200000 + 1][20];
int N;

void maketable() {
	for (int i = 1; i < 20; i++) 
		for (int j = 1; j <= N; j++) 
			f[j][i] = f[f[j][i - 1]][i - 1];

}

int cal(int num, int cnt) {
	int temp = cnt;
	for (int i = 0; cnt; i++) {
		if (cnt & 1) num = f[num][i];
		cnt >>= 1;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> f[i][0];

	maketable();

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << cal(b,a) << "\n";
	}
	return 0;
}