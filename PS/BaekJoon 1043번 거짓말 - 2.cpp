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

int N, M, k;
vector<int> know;
vector<vector<int>> v(50);

int parents[50 + 1];

int _Find(int x) {
	return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
	a = _Find(a), b = _Find(b);
	a < b ? parents[b] = a : parents[a] = b;
}

int main() {
	fastio;
	cin >> N >> M >> k;
	know.resize(k);
	for (int i = 0; i < k; i++) cin >> know[i];

	for (int i = 1; i <= N; i++) parents[i] = i;

	for (int i = 0; i < M; i++) {
		int p; cin >> p;
		int prev, num;
		for (int j = 0; j < p; j++) {
			if (j == 0) cin >> num;
			else {
				prev = num;
				cin >> num;
				_Union(prev, num);
			}
			v[i].push_back(num);
		}
	}

	for (auto TC : v) {
		bool flag = false;
		for (auto list : TC) {
			if (flag) break;
			for (auto check : know) {
				if (_Find(list) == _Find(check)) flag = true;
			}
		}
		if (flag) M--;
	}

	cout << M << "\n";
	return 0;
}