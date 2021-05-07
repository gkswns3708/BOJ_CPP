#include <bits/stdc++.h>
#define int long long int
using namespace std;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	s = ' ' + s;
	pair<int, int> pos[26 + 1];
	for (int i = 0; i < 26; i++) {
		pos[i].first = pos[i].second = -1;
	}
	int cnt = 0;
	for (int i = 1; i <= 52; i++) {
		if (pos[s[i] - 'A'].first == -1) pos[s[i] - 'A'].first = i;
		else pos[s[i] - 'A'].second = i;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (pos[i].first < pos[j].first
				&& pos[i].second > pos[j].first
				&& pos[i].second < pos[j].second) cnt++;
		}
	}
	cout << cnt;
	return 0;
}