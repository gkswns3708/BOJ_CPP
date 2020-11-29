#pragma once
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
int N, M; 
int arr[100000 + 1];
bool cal(int a) {
	ll cnt = 1;
	ll sum = a;
	for (int i = 0; i < N; i++) {
		if (arr[i] > a) return false;
		if (sum - arr[i] < 0) {
			sum = a;
			cnt++;
		}
		sum -= arr[i];
	}
	return M >= cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll sum = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp; cin >> arr[i];sum += arr[i];
	}
	ll l = 1; ll r = sum;
	ll ans = sum;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (cal(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	
	return 0;
}

