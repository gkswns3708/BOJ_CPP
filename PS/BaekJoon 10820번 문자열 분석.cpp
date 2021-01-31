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
	regex r1(R"([a-z])");
	regex r2(R"([A-Z])");
	regex r3(R"([0-9])");
	regex r4(R"([\s])");
	smatch m1, m2, m3, m4;
	string s;
	while (getline(cin, s)) {
		vector<string> vec[4];
		for (auto iter = sregex_iterator(all(s), r1); iter != sregex_iterator(); iter++) {
			cout << iter->str() << " ";
			vec[0].push_back(iter->str());
		}
		for (auto iter = sregex_iterator(all(s), r2); iter != sregex_iterator(); iter++) {
			vec[1].push_back(iter->str());
		}
		for (auto iter = sregex_iterator(all(s), r3); iter != sregex_iterator(); iter++) {
			vec[2].push_back(iter->str());
		}
		for (auto iter = sregex_iterator(all(s), r4); iter != sregex_iterator(); iter++) {
			vec[3].push_back(iter->str());
		}

		cout << vec[0].size() << " " << vec[1].size() << " " << vec[2].size() << " " << vec[3].size() << "\n";
	}
}