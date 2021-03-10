#include <iostream>
#include <algorithm>
#include <vector>

#define int long long int
using namespace std;



int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	int M; cin >> M;
	vector<int> vec(N);
	vector<int> prefix_sum(N + 1);
	for (int i = 0; i < N; i++) cin >> vec[i];
	
	sort(vec.begin(), vec.end());
	
	for (int i = 1; i <= N; i++) {
		prefix_sum[i] += prefix_sum[i - 1] + vec[i-1];
	}
	while (M--) {
		int st, ed; cin >> st >> ed;
		cout << prefix_sum[ed] - prefix_sum[st - 1] << "\n";
	}
	return 0;
}