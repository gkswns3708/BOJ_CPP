#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int n, x; cin >> n >> x;
		vector<int> vec(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}
		ll max = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			max += vec[i] / x;
			if (vec[i] % x != 0) max++;
			sum += vec[i];
			//cout << max << " ";
		}
		ll min = sum / x;
		if (sum % x != 0) min++;
		cout << min << " " << max << "\n";
	}
	return 0;
}