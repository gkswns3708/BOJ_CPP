#include <bits/stdc++.h>
#include <initializer_list>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;

int N;
string s[101];
int cnt;
int cnt2[27];
int arr[27][27];
int main(void) {
	fastio;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	for (int i = 0; i < 26; i++) cnt2[i] = -1;
	for (int i = 0; i < N; i++) {
		for (auto a : s[i]) {
			if (cnt2[a - 'a'] == -1) {
				cnt2[a - 'a'] = 0;
				cnt++;
			}
		}
	}
	char firstchar = s[0][0];
	for (int i = 1; i < N; i++) {
		char nowchar = s[i][0];
		if (firstchar != nowchar) {
			if (arr[firstchar - 'a'][nowchar - 'a'] == 0) {
				arr[firstchar - 'a'][nowchar - 'a'] = 1;
				cnt2[nowchar - 'a']++;
			}
			firstchar = nowchar;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int pos = 1; pos <= 10; pos++) {
				if (pos <min(s[i].length(), s[j].length())) {
					string istr = s[i].substr(0, pos);
					string jstr = s[j].substr(0, pos);
					if (istr == jstr && s[i][pos] != s[j][pos] && arr[s[i][pos] - 'a'][s[j][pos] - 'a']== 0) {
						arr[s[i][pos] - 'a'][s[j][pos] - 'a'] = 1;
						cnt2[s[j][pos] - 'a']++;
					}
				}
				if (pos == min(s[i].length(), s[j].length()) && (s[i].length() > s[j].length()) && s[i].substr(0, pos) == s[j].substr(0, pos)) {
					cout << "!";
					return 0;
				}
			}
		}
	}
	
	queue<int> que;
	vector<int> ans;
	for (int i = 0; i < 26; i++) if (cnt2[i] == 0) que.push(i);
	while (!que.empty()) {
		if (que.size() > 1) {
			cout << "?";
			return 0;
		}
		int nowpos = que.front();
		ans.push_back(nowpos);
		que.pop();
		for (int i = 0; i < 26; i++) {
			if (arr[nowpos][i] == 0) continue;
			if (--cnt2[i] == 0)que.push(i);
		}
	}
	if (ans.size() != cnt) cout << "!";
	else for (auto a : ans) {
		char nowchar = a + 'a';
		cout << nowchar;
	}
	return 0;
}