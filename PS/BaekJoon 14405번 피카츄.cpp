#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
	fastio;
	string s; cin >> s;
	regex r(R"(^((pi)*(ka)*(chu)*){1,})");
	sregex_iterator it;
	smatch m;
	vector<string> v;
	bool found = regex_search(s, m, r);
	for (auto it = sregex_iterator(s.begin(), s.end(), r);; it++) {
		v.push_back(it->str());
	}
	for (auto a : v)
		cout << a << "\n";
	regex_match(s, r) ? cout << "YES" : cout << "NO";
}