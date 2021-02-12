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
using tiii = tuple<int, int, int>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }


int N;
vector<tiii> vec;
vector<pii> ans;
map<int, int> mp;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int lx, h, rx; cin >> lx >> h >> rx;
		vec.push_back({ lx, rx, h });
	}
}
void solution() {
	sort(all(vec));
	int size = vec.size();
	int h = 1;
	int plx = -1, prx = -1, ph = -1;
	for (int i = 0; i < size; i++) {
		auto [nlx, nrx, nh] = vec[i];
		//¾È °ãÄ¥ ¶§
		if (prx < nlx) {
			ans.push_back({ prx,ph });

		}

	}
}

int main() {
	fastio;
	input();
	solution();
}