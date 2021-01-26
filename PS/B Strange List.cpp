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
		vector<pair<int,int>> vec(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) cin >> vec[i].first, vec[i].second = 1, sum += vec[i].first;
		bool shutdown = false;
		int start = 0, end = n;


		while (start < end) {
			int cnt = 0;
			for (int i = start; i < end; i++) {
				if (vec[i].first % x) {
					shutdown = true;
				}
				else {
					if (!shutdown) {
						vec.push_back({ vec[i].first / x, vec[i].second * x });
						sum += (vec[i].first / x) * vec[i].second * x;
					}
					cnt++;
				}
			}
			if (shutdown) break;
			start = end;
			end = start + cnt;
		}
		
		cout << sum << "\n";
	}

	return 0;
}