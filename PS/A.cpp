#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		vector<int> vec(N + 1);
		for (int i = 0; i < N; i++) {
			int temp; cin >> temp; vec[temp]++;
		}
		int ans = 0;;
		for (int i = 0; i <= N; i++) {
			ans = max(ans, vec[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}