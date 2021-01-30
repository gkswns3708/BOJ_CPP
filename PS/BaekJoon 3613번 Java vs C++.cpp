#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int main() {
	fastio;
	string s; cin >> s;
	regex a(R"([a-z]+(_[a-z]+)*)"), b(R"([a-z]+([A-Z][a-z]*)*)");
	smatch m;
	if (regex_match(s, m, a)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '_')
				cout << char(s[++i] - 'a' + 'A');
			else
				cout << s[i];
		}
		cout << '\n';
	}
	else {
		if (regex_match(s, m, b)) {
			for (int i = 0; i < s.length(); i++) {
				if ('A' <= s[i] && s[i] <= 'Z')
					cout << '_' << char(s[i] - 'A' + 'a');
				else cout << s[i];
			}
			cout << '\n';
		}
		else {
			cout << "Error!";
		}
	}
	return 0;
}