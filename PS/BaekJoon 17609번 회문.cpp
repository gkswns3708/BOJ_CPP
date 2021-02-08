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

string s;
int len;

bool checkpalin(int st,int ed) {	
	for (; st < ed; st++, ed--) {
		if (s[st] != s[ed]) return false;
	}
	return true;
}

int solution(string s) {
	int ans = 0;
	if (checkpalin(0,len-1)) return 0;
	for (int st = 0, ed = len-1; st < ed; st++ ,ed--) {
		if (s[st] != s[ed]) {
			if (checkpalin(st + 1, ed)) return 1;
			if (checkpalin(st, ed - 1)) return 1;
			return 2;
		}
	}
	return 2;
}

void input() {
	int TC; cin >> TC;
	while (TC--) {
		cin >> s;	
		len = s.length();
		cout << solution(s)<<"\n";
	}
}

int main() {
	fastio;
	input();
	return 0;
}