#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N, K, Q;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> K >> Q;
	for (int i = 0; i < Q; i++) {
		ll a, b; cin >> a >> b;
		ll ans = 0;
		if (K == 1) cout << abs(a - b) << "\n";
		else {
			while (a != b) {
				if (a > b) a = (a - 2) / K + 1;
				else b = (b - 2) / K + 1;
				ans++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}