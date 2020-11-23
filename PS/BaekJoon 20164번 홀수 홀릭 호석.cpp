#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

pair<int, int> recul(string s) {
	int length = s.length();
	int cnt = 0;
	for (int i = 0; i < length; i++)
		if ((s[i] - '0') % 2) cnt++;
	int mn = INT_MAX;
	int mx = INT_MIN;
	if (length == 1)
		mn = mx = 0;
	else if (length == 2) {
		pair<int, int> nowpair = recul(to_string(s[0] - '0' + s[1] - '0'));
		mn = min(mn, nowpair.first);
		mx = max(mx, nowpair.second);
	}
	else {
		int beforecnt = 0;
		for (int i = 1; i <= length - 2; i++) {
			for (int j = i + 1; j <= length - 1; j++) {
				string s1, s2, s3;
				s1 = s.substr(0, i);
				s2 = s.substr(i, j - i);
				s3 = s.substr(j, length - j);
				int sum = 0;
				sum += stoi(s1);
				sum += stoi(s2);
				sum += stoi(s3);
				pair<int, int> nowpair = recul(to_string(sum));
				mn = min(mn, nowpair.first);
				mx = max(mx, nowpair.second);
			}
		}
	}
	return { cnt + mn,cnt + mx };
}


int main() {
	fastio;
	string s; cin >> s;
	pair<int, int> pii = recul(s);
	cout << pii.first << " " << pii.second;
	return 0;
}
