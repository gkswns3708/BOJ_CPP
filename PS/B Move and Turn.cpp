#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll N;	cin >> N;
	ll dot = 0, times = 0;
	ll ans = 0;
	if (N % 2 == 1) {
		dot = N / 2 + 2;
		times = N / 2 + 1;
		ans = 2 * dot * times;
	}
	else {
		dot += (N) / 2+1;
		times += (N)/2+1;
		ans = dot * times;
	}
	cout << ans << "\n";
	return 0;
}