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
int parents[20000 + 1];
int cost[20000 + 1];

int _Find(int x) {
	if (parents[x] == x) return x;
	int tmp = _Find(parents[x]);
	cost[x] += cost[parents[x]];
	return parents[x] = tmp;;
}

void _Union(int a, int b) {
	cost[a] = abs(a - b) % 1000;
	parents[a] = b;
}

void solution() {
	cin >> N;
	char cmd;
	for (int i = 0; i <= N; ++i) {
		parents[i] = i;
		cost[i] = 0;
	}
	while (cin >> cmd, cmd !='O') {
		if (cmd == 'E') {
			int num; cin >> num;
			_Find(num);
			cout << cost[num] << "\n";
		}
		if (cmd == 'I') {
			int a, b; cin >> a >> b;
			cost[a] = abs(a - b) % 1000;
			parents[a] = b;
		}
	}
}

int main() {
	fastio;
	int TC; cin >> TC;
	while (TC--) solution();

}