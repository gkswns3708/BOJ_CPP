#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, d, N; cin >> a >> b >> d >> N;
	int ans = 1, sum = 0;
	vector<int> vec(N + 1);
	vec[0] = 1;
	for (int i = 1; i <= N; i++) {
		if (i >= b) sum -= vec[i - b] - 1000, sum %= 1000;
		if (i >= a) sum += vec[i - a], sum %= 1000;
		vec[i] = sum;
		ans += vec[i];
		if (i >= d) ans -= vec[i - d] - 1000, sum %= 1000;
	}
	cout << ans % 1000;
	return 0;
}