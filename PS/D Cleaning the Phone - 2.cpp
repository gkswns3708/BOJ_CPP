#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#pragma once
using namespace std;
typedef long long int ll;

bool compare(int a, int b) {
	return a < b;
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int n, m; cin >> n >> m;
		vector<int> a(n), b(n),vec(n+1);
		int acnt = 0, bcnt = 0;
		for (int i = 0; i < n; i++) cin >> vec[i];
		//나누기
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			if (temp == 1)a[acnt++] = vec[i];
			else b[bcnt++] = vec[i];
		}
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());
		a.push_back(0);
		a.push_back(0);
		b.push_back(0);
		int i = 0, j = 0;
		ll ans = 0;
		while (m > 0 && (i < acnt|| j < bcnt)) {
			//1 1개를 고를 때 끝나면 1를 고르고 끝 아니면 1을 1개 고름.
			if (a[i] >= m || a[i] + a[i + 1] > b[j]) m -= a[i++], ans += 1;
			else m -= b[j++], ans += 2;
		}
		if (m > 0) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}