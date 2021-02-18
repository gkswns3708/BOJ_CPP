#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define MAX 10000+1
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

//Union할 때 작은 수가 아닌 cost값이 가장 작은 값을 가르키도록 Union하면 될 듯 하다.

int N, M, k;
int cost[MAX];
int parents[MAX];
bool check[MAX];

int _Find(int x) {
	return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
	a = _Find(a), b = _Find(b);
	cost[a] < cost[b] ? parents[b] = a : parents[a] = b;
}

int main() {
	fastio;
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) cin >> cost[i];
	for (int i = 1; i <= N; i++) parents[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		_Union(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int now = _Find(i);
		if (!check[now]) {
			ans += cost[now];
			check[now] = true;
		}
	}
	if (ans > k)  cout << "Oh no\n";
	else cout << ans << "\n";
}