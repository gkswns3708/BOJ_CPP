#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int ans;

int main() {
	fastio;
	string s, s1;
	getline(cin, s);
	getline(cin, s1);
	auto pos = s.find(s1);
	while (pos != string::npos) ans++, pos = s.find(s1, pos + s1.size());
	cout << ans;
	return 0;
}