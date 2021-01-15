#include <bits/stdc++.h>
#pragma once
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string ss; cin >> ss;
	char  s[26 + 1] = {0,};
	bool arr[27] = { 0, };
	for (int i = 0; i < ss.length(); i++) {
		s[i] = ss[i];
		arr[ss[i] - 'a'] = true;
	}
	string ans = "";
	if (ss.length() == 26) {
		if (next_permutation(s, s + 27) == true)
			for (int i = 0; i < 26; i++) {
				if (s[i] >= 'a' && s[i] <= 'z') ans += s[i];
				else break;
			}
		else ans = "-1";
	}
	else {
		for (int i = 0; i < 26; i++)
			if (arr[i] == false) {
				char newchar = (i + 'a');
				ss = ss + newchar;
				break;
			}
		ans = ss;
	}

	cout << ans;
	return 0;
}