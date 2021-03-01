#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//접두사와 접미사의 최대 크기를 담고 있는 table
vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j-1];
		}
		if (pattern[i] == pattern[j]) table[i] = ++j;
	}
	return table;
}

bool KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize -1) {
				j = table[j];
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

	//최대 일치 테이블 구성
	string parent; cin >> parent;
	string pattern; cin >> pattern;
	if (KMP(parent, pattern)) cout << 1;
	else cout << 0;
	
	return 0;
}