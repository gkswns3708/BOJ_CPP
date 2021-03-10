#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long int

int arr[2000 + 1][2000 + 1];
int prefix_sum[2000 + 1][2000 + 1];
int ans[2000 + 1][2000 + 1];
int N, M;

void update(int x, int y) {
	prefix_sum[x][y] = prefix_sum[x - 1][y] + prefix_sum[x][y - 1] - prefix_sum[x-1][y-1] + ans[x][y];
}

bool possible(int x, int y) {
	return x <= N && x >= 1&& y <= N && y >= 1;
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j<= N; j++) {
		int temp; cin >> temp;
		arr[i][j] = -temp;
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (possible(i + M / 2, j + M / 2)) {
			update(i + M / 2, j + M / 2);
			int x1 = max(i - M / 2, 1LL), y1 = max(j - M / 2, 1LL);
			int x2 = min(i + M / 2, N), y2 = min(j + M / 2, N);
			int sum = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
			ans[i + M / 2][j + M / 2] = arr[i][j] - sum;
			update(i + M / 2, j + M / 2);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) 
			cout << ans[i][j] << " ";	
		cout << "\n";
	}
	

	return 0;
}