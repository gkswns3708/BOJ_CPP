#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int idx = 1;
	while (1) {
		string s; cin >> s;
		stack<char> stk;
		if (s[0] == '-') break;
		int ans = 0;
		int size = s.length();
		char temp = ' ';
		for (int i = 0; i < size; i++) {
			if (stk.empty()) {
				if (s[i] == '{') stk.push(s[i]);
				else {
					stk.push('{');
					ans++;
				}
			}
			else {
				if (s[i] == '{') stk.push(s[i]);
				else {
					stk.pop();
				}
			}
		}
		ans += stk.size() / 2;
		cout << idx++ << ". " << ans << "\n";
	}
	return 0;
}