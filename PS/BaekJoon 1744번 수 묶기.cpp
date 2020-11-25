#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	fastio;
	int N; cin >> N;
	ll ans = 0;
	vector<int> plusvec;
	vector<int> minusvec;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		if (temp <= 0) minusvec.push_back(temp);
		else if (temp == 1) ans++;
		else plusvec.push_back(temp);
	}
	sort(plusvec.begin(), plusvec.end(), compare);
	sort(minusvec.begin(), minusvec.end());
	int psize = plusvec.size();
	int msize = minusvec.size();
	for (int i = 0; i < psize; i += 2) {
		if (i + 1 == psize) ans += plusvec[i];
		else ans += 1LL * plusvec[i] * plusvec[i + 1];
	}
	for (int i = 0; i < msize; i += 2) {
		if (i + 1 == msize) ans += minusvec[i];
		else ans += 1LL * minusvec[i] * minusvec[i + 1];
	}
	cout << ans;
	return 0;
}