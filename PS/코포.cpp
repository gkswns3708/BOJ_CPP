#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define int long long int
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



int32_t main() {
	fastio;
	int TC; cin >> TC;
	while (TC--) {
		int n, m; cin >> n >> m;
		vector<int> vecp, vecm;
		vector<int> vecbp, vecbm;
		int now;
		for (int i = 0; i < n; i++) {
			cin >> now;
			if (now > 0) vecp.push_back(now);
			else vecm.push_back(-now);
		}
		for (int i = 0; i < m; i++) {
			cin >> now;
			if (now > 0) vecbp.push_back(now);
			else vecbm.push_back(-now);
		}
		//sort(all(vecp));
		//sort(all(vecm));
		//sort(all(vecbp));
		//sort(all(vecbm));
		for (int i = 0; i < vecp.size(); i++) {

		}
	}
}