#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;

int N;
ll arr[1001][5];
ll solution(int n, int r) {
	if (n == 1) return 1;
	if (r == 3) return pow(2, n) - 1;
	ll k = n - round(sqrt(2 * n + 1)) + 1;
	ll& result = arr[n][r];
	return result = 2 * solution(k, r) + solution(n - k, r - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	while ((cin >> N)) {
		cout << "Case " << cnt++ << ": " << solution(N, 4) << "\n";
	}
	return 0;
}