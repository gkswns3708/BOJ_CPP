#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int N, M, st = 0, ed = int(1e9);
vector<int> vec;

bool possible(int mid) {
	int sum = 0;
	int cnt = 0;
	for (auto now : vec) {
		if (sum + now > mid) {
			sum = now;
			cnt++;
		}
		else sum += now;
	}
	return cnt+1 <= M;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];

	while (st + 1 < ed) {
		int mid = (st + ed) / 2;
		if (possible(mid)) 	ed = mid;
		else st = mid;
	}
	int sum = 0, ans = 0;
	for (auto now : vec) {
		if (sum + now > ed) {
			ans = max(ans, sum);
			sum = now;
		}
		else sum += now;
	}
	
	cout << max(sum, ans);
	return 0;
}