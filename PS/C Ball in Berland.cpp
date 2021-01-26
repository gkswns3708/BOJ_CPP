#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int a, b, k;
		cin >> a >> b >> k;
		vector<pair<int, int>> pii(k+1);
		vector<int> avec(a + 1), bvec(b + 1);
		for (int i = 0; i < k; i++) {
			cin >> pii[i].first;
			avec[pii[i].first]++;
		}
		for (int i = 0; i < k; i++) {
			cin >> pii[i].second;
			bvec[pii[i].second]++;
		}
		ll cnt = 0;
		for (int i = 0; i < k; i++) {
			int nowa = pii[i].first;
			int nowb = pii[i].second;
			cnt += k - (avec[nowa] + bvec[nowb] - 1);
		}
		cout << cnt/2 <<"\n";
	}
	return 0;
}