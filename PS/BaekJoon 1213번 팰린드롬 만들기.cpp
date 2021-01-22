#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int arr[26+1] = { 0, };

	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) arr[s[i] - 'A']++;


	int cnt = 0;
	for (int i = 0; i < 27; i++) {
		if (arr[i] % 2 == 1) cnt++;
	}
	if (cnt >= 2) cout << "I\'m Sorry Hansoo" << "\n";
	else {
		int pos = -1;
		for (int i = 0; i < 26; i++) {
			if (arr[i]%2== 1) pos = i;
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < arr[i]/2; j++) {
				//cout << "1";
				cout << char(i + 'A');
			}
		}
		if (pos != -1) cout << char(pos + 'A');
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < arr[i] / 2; j++) {
				//cout << "2";
				cout << char(i+ 'A');
			}
		}
	}
	return 0;
}