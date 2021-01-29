#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<tuple<ll,ll,ll>> vec;
int one;

bool compare(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) {
	auto [A, B, C] = a;
	auto [D, E, F] = b;
	if (A == D) return B > E;
	return A < D;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll temp; cin >> temp;
		ll ttemp = temp;
		int X = 0, Y = 0;
		while (!(temp % 2)) {
			X++;
			temp /= 2;
		}
		while (temp) {
			Y++;
			temp /= 3;
		}
		vec.push_back({ X,Y,ttemp });
	}
}

void solution() {
	sort(all(vec), compare);
	for (auto a : vec) {
		auto [b, c, d] = a;
		cout << d << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}