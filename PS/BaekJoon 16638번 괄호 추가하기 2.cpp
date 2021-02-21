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

int N;
string s;
int mx = INT_MIN;

int cal(vector<int> num, vector<char> cmd) {
	for (int i = 1; i <= cmd.size(); i++) {
		if (cmd[i-1] == '*') {
			num[i-1] *= num[i];
			cmd.erase(cmd.begin() + i -1);
			num.erase(num.begin() + i);
			i--;
		}
	}
	int now = num[0];
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i] == '+') now += num[i + 1];
		if (cmd[i] == '-') now -= num[i + 1];
	}
	return now;
}

int parsing(string ns) {
	vector<int> num;
	num.push_back(ns[0] - '0');
	vector<char> cmd;
	for (int i = 1; i < ns.size(); i+=2) {
		cmd.push_back(ns[i]);
		num.push_back(ns[i + 1] - '0');
	}
	return cal(num, cmd);
}

void input() {
	cin >> N >> s;
}

void DFS(vector<int> num, vector<char> cmd, int cur) {
	if (cur >= s.size()) {
		mx = max(mx, cal(num, cmd));
		return;
	}
	for (int i = 0; cur + i < s.size() && i <= 2; i += 2) {
		if (cur) cmd.push_back(s[cur - 1]);
		num.push_back(parsing(s.substr(cur, i+1)));
		DFS(num, cmd, cur + i + 2);
		if (cur) cmd.pop_back();
		num.pop_back();
	}
}

void solution() {
	DFS(vector<int> {}, vector<char>{}, 0);
	cout << mx;
}

int main() {
	fastio;
	input();
	solution();
}