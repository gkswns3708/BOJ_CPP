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
int N, M,ans;

void input() {
	cin >> N >> M;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
}

void solution() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += vec[i];
		if (sum> M) sum = vec[i],ans++;
		
	}
	if (N == 0) cout << ans;
	else cout << ans + 1 << "\n";
}

int main() {
	fastio;
	input();
	solution();
}