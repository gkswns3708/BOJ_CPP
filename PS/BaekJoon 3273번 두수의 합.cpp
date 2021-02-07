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

vector<int> vec;
int N,value;

void input() {
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	cin >> value;
}

void solution() {
	sort(all(vec));
	int ans = 0;
	int st = 0, ed = N - 1;
	while (st < ed) {
		int now = vec[st] + vec[ed];
		if (now > value) ed--;
		else if (now == value) {
			ans++;
			st++;
			ed--;
		}
		else st++;
	}
	cout << ans;
}

int main() {
	fastio;
	input();
	solution();
}