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

int K;

void input() {
	cin >> K;
}

void solution() {
	int now = 1;
	int cnt = 0;
	while (now < K) now <<= 1;
	cout << now << " ";
	int sum = 0;
	while (now >= 1) {
		if (sum + now <= K) sum += now;
		now >>= 1;
		cnt++;
		if (sum == K) {
			cout << cnt - 1;
			break;
		}
	}
}

int main() {
	fastio;
	input();
	solution();
}