#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	int ans[27] = { 0, };
	for (int i = 0; i < s.length(); i++) ans[tolower(s[i]) - 'a']++;
	
	bool same = false;
	int maxvalue = 0,maxpos = -1;
	for (int i = 0; i < 26; i++) {
		if (ans[i] == maxvalue) {
			same = true;
		}
		else if (ans[i] > maxvalue) {
			maxvalue = ans[i];
			maxpos = i;
			same = false;
		}
	}
	
	same ? cout << "?" : cout << (char)('A' + maxpos);

	return 0;
}