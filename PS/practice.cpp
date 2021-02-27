#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;
ll N; 
vector<ll> tree;
ll sol(ll l, ll r) {
	if (l >= N) return max(tree[l], tree[r]);
	return max(tree[l] + sol(r << 1, r << 1 | 1), sol(l << 1, l << 1 | 1) + tree[r]);
}
vector<ll> tree;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	tree.resize(N << 1);
	for (ll i = N; i < (N << 1); i++) cin >> tree[i];
	for (ll i = N - 1; i >= 1; i--) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
	cout << sol(2, 3) << '\N';
}