#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> vec(M);
	for (int i = 0; i < M; i++) cin >> vec[i];
	int st = 0, ed = int(1e9)+1;
	int now = -1;
	while (st + 1 < ed) {
		int mid = (st + ed) / 2;
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			cnt += vec[i] / mid;
			cnt += bool(vec[i] % mid);
		}
		if (cnt <= N) {
			now = mid;
			ed = mid;
		}
		else st = mid;
	}
	cout << now;
	return 0;
}