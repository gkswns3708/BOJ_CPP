#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	map<string, int> mp;
	string s; cin >> s;
	int len = s.length();
	for (int pos = 0; pos < len; pos++)for (int i = 1; pos + i <= len; i++) mp[s.substr(pos, i)]++;
	cout << mp.size();
	return 0;
}