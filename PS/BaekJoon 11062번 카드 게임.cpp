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
int dp[1000 + 1][1000 + 1][2];
vector<int> vec;

void input() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	vec.clear();
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
}

ll DP(int st, int ed,bool flag) {
	int& ret = dp[st][ed][flag];
	if (ret != -1) return ret;
	if (st >= ed) {
		if (!flag) return ret = vec[st];
		else return ret = 0;
	}
	if (!flag) {
		return ret = max(DP(st + 1, ed, !flag) + vec[st], DP(st, ed - 1, !flag) + vec[ed]);
	}
	else {
		return ret = min(DP(st + 1, ed, !flag), DP(st, ed - 1, !flag));
	}
}

int main() {
	fastio;
	int TC; cin >> TC;
	while (TC--) {
		input();
		cout << DP(0, N - 1,0) << "\n";
	}
}