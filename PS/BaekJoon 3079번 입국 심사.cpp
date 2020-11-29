#pragma once
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll N, M; cin >> N >> M;
	ll arr[100000 + 1] = { 0, };
	ll maxval = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		maxval = max(maxval, arr[i]);
	}
	ll r = maxval * M, l = 1, ans = maxval * M;
	while (l <= r) {
		ll mid = (r + l) / 2;
		ll nowperson = 0;
		for (int i = 0; i < N; i++)
			nowperson += mid / arr[i];
		if (nowperson >= M) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}

