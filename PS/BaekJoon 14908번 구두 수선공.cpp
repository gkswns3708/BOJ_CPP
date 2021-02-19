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
vector<pair<int,double>> vec;

void input() {
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		double a, b; cin >> a >> b;
		vec[i] = {i+1, b/a };
	}
	sort(all(vec), [](pair<int, double> a, pair<int, double> b) {
		if (a.second == b.second) return a.first < b.first;
		else return a.second > b.second;});
	for (auto now : vec) cout << now.first <<' ';
}

int main() {
	fastio;
	input();
}