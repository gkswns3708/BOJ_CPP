#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

ll arr[5000 + 1];

ll solution(int length) {
	if (length == 0)
		return 1;

	ll& ans = arr[length];
	if (ans >= 0)
		return ans;

	ans = 0;
	for (int i = 2; i <= length; i += 2) {
		ans += solution(i-2) * solution(length - i);
		ans %= MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	memset(arr, -1, sizeof(arr));
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		ll temp;
		N % 2 == 0 ? temp = solution(N) : temp = 0;
		cout << temp << "\n";
	}

	return 0;
}