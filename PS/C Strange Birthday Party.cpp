#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int TC; cin >> TC;
	while (TC--) {
		int n, m; cin >> n >> m;

		ll ans = 0;
		vector<int> k(n+1);
		vector<int> c(m+1);
		for (int i = 1; i <= n; i++) cin >> k[i];
		for (int i = 1; i <= m; i++) cin >> c[i];	
		for (int i = 1; i <= n; i++) ans += c[k[i]];
		sort(k.begin(), k.end());
		int cnt = 1;
		for (int i = n; i >= 1; i--) {
			if (k[i] >= cnt) {
				ans -= c[k[i]];
				ans += c[cnt];
				cnt++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}