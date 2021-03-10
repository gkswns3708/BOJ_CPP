#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	regex r(R"([A-Z][a-z]*)");
	vector<string> vec;
	for (auto it = sregex_iterator(s.begin(), s.end(), r); it != sregex_iterator(); it++) vec.push_back(it->str());
	int ans = 0;
	for (int i = 0; i < int(vec.size()) - 1; i++) 	if (vec[i].size() % 4) 	ans += 4 - vec[i].size() % 4;
	cout << ans;
	return 0;
}