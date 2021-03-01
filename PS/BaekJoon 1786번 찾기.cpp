#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> ans;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = table[j - 1];
		if (pattern[i] == pattern[j]) table[i] = ++j;
	}
	return table;
}

void KMP(string parent, string pattern) {
	int parentSize = parent.size(), patternSize = pattern.size();
	vector<int> table = makeTable(pattern);
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (parent[i] != pattern[j] && j > 0) j = table[j - 1];
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				ans.push_back(i - patternSize + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string parent;
	getline(cin, parent);
	string pattern;
	getline(cin, pattern);

	KMP(parent, pattern);
	cout << ans.size() << "\n";
	for (int now : ans) cout << now << " ";
	return 0;
}