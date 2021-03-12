#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	regex r(R"((^\w+)://([^:/]+)(?::(\d+))?(?:/(.+$))?)");
	for (int tc = 1; tc++ <= TC;) {
		string s; cin >> s;
		string ans[4];
		auto it = *sregex_iterator(s.begin(), s.end(), r);
		for (int i = 0; i < 4; i++) {
			ans[i] = it[i + 1];
			if (ans[i].empty()) ans[i] = "<default>";
		}
		cout << "URL #" << tc  << '\n';
		cout << "Protocol = " << ans[0] << '\n';
		cout << "Host     = " << ans[1] << '\n';
		cout << "Port     = " << ans[2] << '\n';
		cout << "Path     = " << ans[3] << '\n' << '\n';
	}
	return 0;
}