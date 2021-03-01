#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string _find(string s) {
	string ret;
	for (int i = 0; i < s.length(); ++i) if (!(s[i] >= '0' && s[i] <= '9')) ret.push_back(s[i]);
	return ret;
}

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) table[i] = ++j;
	}
	return table;
}

bool KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int j = 0;
	for (int i = 0; i < parent.size(); ++i) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				return 1;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	string parent = _find(s);
	string pattern; cin >> pattern;

	if (KMP(parent, pattern)) cout << 1;
	else cout << 0;

	return 0;
}