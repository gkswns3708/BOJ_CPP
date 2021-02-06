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

void solution() {
	int N, pos,cnt = 0,ans = 0; cin >> N >> pos;
	deque<pii> deq;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		deq.push_back({ temp,cnt++ });
	}
	while (1){
		bool flag = true;
		auto [now, npos] = deq.front();
		for (auto nxt : deq) if (nxt.X > now) flag = 0;
		if (flag) {
			ans++;
			if (npos == pos) break;
			else deq.pop_front();
		}
		else {
			deq.push_back(deq.front());
			deq.pop_front();
		}
	}
	cout << ans << "\n";

}

void input() {
	int TC; cin >> TC;
	while (TC--) {
		solution();
	}
}

int main() {
	fastio;
	input();
}