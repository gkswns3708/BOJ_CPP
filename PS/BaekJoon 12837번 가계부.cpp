#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;

struct ST {
	ll tree[1 << 21];
	int size = 1 << 20;

	void update(int idx, int val) {
		--idx |= size; tree[idx] += val;
		while (idx >>= 1)
			tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	ll query(int l, int r) {
		--l |= size; --r |= size;
		ll sum = 0;
		while (l < r) {
			if (l & 1) sum += tree[l++];
			if (r & 1) sum += tree[--r];
			l >>= 1;
			r >>= 1;
		}
		return sum;
	}
}ST;

int main() {
	fastio;
	int n, m; cin >> n >> m;
	while (m--) {
		int type, idx, value; cin >> type >> idx >> value;
		if (type == 1) 	ST.update(idx, value);
		else cout << ST.query(idx, value+1) << "\n";
	}
	return 0;
}