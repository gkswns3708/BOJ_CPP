#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int n; cin >> n;
		int cnt1 = 0, cnt2 = 0;
		vector<pair<char, char>> vec1(n);
		for (int i = 0; i < n; i++) {
			cin >> vec1[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> vec1[i].second;
		}
		for (int i = 0; i < n; i++) {
			if (vec1[i].first > vec1[i].second) cnt1++;
			else if (vec1[i].first == vec1[i].second) continue;
			else cnt2++;
		}
		if (cnt1 > cnt2) cout << "RED\n";
		else if (cnt1 == cnt2 )cout << "EQUAL\n";
		else cout << "BLUE\n";
	}
	return 0;
}