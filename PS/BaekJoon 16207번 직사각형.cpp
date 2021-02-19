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
vector<int> vec;

void input() {
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
}

void solution() {
	sort(all(vec),greater<int>());
	ll sum = 0;
	vector<int> temp;
	for (int i = 0; i < N;) {
		int now = i;
		while (now + 1 < N && vec[now] - vec[now + 1] <= 1) now++;
		for (int j = i; j + 1 <= now; j += 2) temp.push_back(vec[j + 1]);
		i = now + 1;
	}
	for (int i = 0; i + 1 < temp.size(); i += 2) sum += 1ll * temp[i] * temp[i + 1];
	cout << sum;
}

int main() {
	fastio;
	input();
	solution();
}