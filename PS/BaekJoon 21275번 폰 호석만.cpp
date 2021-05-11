#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

bool NaN(char a) {
	if (a >= '0' && a <= '9') return true;
	else return false;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b; cin >> a >> b;
	vector<pii> possiblea, possibleb;
	int maxa = 0, maxb = 0;
	for (auto now : a) {
		if (NaN(now))maxa = max(maxa, int64_t((now - '0')) + 1);
		else maxa = max(maxa, int64_t((now - 'a' + 10)) + 1);
	}
	for (auto now : b) {
		if (now >= '0' && now <= '9')maxb = max(maxb, int64_t((now - '0')) + 1);
		if (now >= 'a' && now <= 'z')maxb = max(maxb, int64_t((now - 'a' + 10)) + 1);
	} 

	for (int i = maxa; i <= 36; i++) {
		int num = 0;
		bool flag = true;
		for (int j = 0; j < a.length(); j++) {
			if (num >= (1ULL << 63 - 1LL * (NaN(a[j]) ? a[j] - '0' : a[j] - 'a' + 10)) / i + (1ULL << 63 - 1LL * (NaN(a[j]) ? a[j] - '0' : a[j] - 'a' + 10)) % i) {
				flag = false;
				break;
			}
			num *= i;
			if (NaN(a[j])) 	num += a[j] - '0';
			else num += a[j] - 'a' + 10;

		}
		if (flag) possiblea.push_back({ num ,i });
	}
	for (int i = maxb; i <= 36; i++) {
		int num = 0;
		bool flag = true;
		for (int j = 0; j < a.length(); j++) {
			if (num >= 1ULL << 63 - 1LL * ((NaN(b[j]) ? b[j] - '0' : b[j] - 'a' + 10)) / i + 1ULL << 63 - 1LL * ((NaN(b[j]) ? b[j] - '0' : b[j] - 'a' + 10)) % i) {
				flag = false;
				break;
			}
			num *= i;
			if (NaN(b[j])) num += b[j] - '0';
			else num += b[j] - 'a' + 10;
		}
		if (flag) possibleb.push_back({ num , i });
	}

	bool flag = false;
	vector<tiii> ans;
	for (auto now : possiblea)
		for (auto nxt : possibleb)
			if (now.first == nxt.first && now.second != nxt.second) ans.push_back({ now.first, now.second , nxt.second });

	if (ans.size() == 0)cout << "Impossible\n";
	else if (ans.size() == 1) {
		auto [a, b, c] = ans.back();
		cout << a << " " << b << " " << c;
	}
	else cout << "Multiple";

	return 0;
}