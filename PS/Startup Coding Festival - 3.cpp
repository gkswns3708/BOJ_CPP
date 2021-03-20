#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <memory.h>
#define int long long int
using namespace std;

int N;
char arr[60][60];
bool possible(int y, int x) {
	if (y >= 0 && y <= N && x >= 0 && x <= N) return true;
	else return false;
}

int check(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] == '0') return 0;
		}
	}
	return 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
	int ans = 0;
	vector<int> answer(N+2,0);

	for (int sz = 1; sz <= N; sz++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (possible(i + sz, j + sz)) {
					cnt +=check(i, j, sz);
				}
			}
		}
		answer[sz] = cnt;
		ans += cnt;
	}
	cout << "total: " << ans << "\n";
	for (int i = 1; i <= N; i++) {
		if (answer[i] == 0) continue;
		cout << "size[" << i << "]: " << answer[i] << "\n";
	}
	return 0;
}