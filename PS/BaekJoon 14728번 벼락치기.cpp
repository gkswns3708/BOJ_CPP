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

int N, T;
int arr[100+1][10000+1];
vector<pii> vec;

void input() {
	cin >> N >> T;
	vec.resize(N+1);
	for (int i = 1; i <= N; i++) cin >> vec[i];
}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = vec[0].first; j <= T; j++) {
			arr[i][j] = arr[i-1][j];
			if (j - vec[i].first >=0 && arr[i - 1][j - vec[i].first] + vec[i].second > arr[i][j]) {
				arr[i][j] = arr[i - 1][j - vec[i].first] + vec[i].second;
			}
		}
	}
	cout << arr[N][T];
}

int main() {
	fastio;
	input();
	solution();
}