#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MOD = int(1e9) + 7;

struct SegTree {
	int tree[1 << 18], lazy[1 << 18][2];
	int sz = 1 << 17;

	void construct() {
		for (int i = sz - 1; i > 0; i--) {
			tree[i] = (tree[i << 1] + tree[i << 1 | 1]) % MOD;
		}
	}
	void propagate(int node, int nodeL, int nodeR) {
		//a, b : n -> a * n + b
		auto& [a, b] = lazy[node];
		if (a == 1 && b == 0) return;
		if (nodeL != nodeR) {
			for (int i = node * 2; i <= node * 2 + 1; i++) {
				auto& [c, d] = lazy[i];
				c = (1LL * a * c) % MOD;
				d = (1LL * a * d + b) % MOD;
			}
		}
		tree[node] = (1LL * a * tree[node] + 1LL * (nodeR - nodeL + 1) * b) % MOD;
		a = 1, b = 0;
	}
	//[l, r] -> mul * [l, r] + sum
	void update(int L, int R, int nodeNum, int nodeL, int nodeR, int mul, int sum) {
		propagate(nodeNum, nodeL, nodeR);
		if (R < nodeL || nodeR < L) return;
		if (L <= nodeL && nodeR <= R) {
			auto& [a, b] = lazy[nodeNum];
			a = (1LL * a * mul) % MOD;
			b = (1LL * b * mul + sum) % MOD;
			propagate(nodeNum, nodeL, nodeR);
			return;
		}
		int mid = nodeL + nodeR >> 1;
		update(L, R, nodeNum << 1, nodeL, mid, mul, sum);
		update(L, R, nodeNum << 1 | 1, mid + 1, nodeR, mul, sum);
		tree[nodeNum] = (tree[nodeNum << 1] + tree[nodeNum << 1 | 1]) % MOD;
	}
	void update(int l, int r, int mul, int sum) {
		update(l, r, 1, 1, sz, mul, sum);
	}
	//[l, r] : 1-indexed
	int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
		propagate(nodeNum, nodeL, nodeR);
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return tree[nodeNum];
		int mid = nodeL + nodeR >> 1;
		return (query(L, R, nodeNum << 1, nodeL, mid) + query(L, R, nodeNum << 1 | 1, mid + 1, nodeR)) % MOD;
	}
	int query(int l, int r) {
		return query(l, r, 1, 1, sz);
	}
} ST;

int main() {
	fastio;
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> ST.tree[ST.sz + i];
	for (int i = 0; i < 1 << 18; i++) ST.lazy[i][0] = 1;
	ST.construct();
	int q; cin >> q;
	while (q--) {
		int t, a, b, k; cin >> t >> a >> b;
		if (t != 4) cin >> k;
		if (t == 1) ST.update(a, b, 1, k);
		else if (t == 2) ST.update(a, b, k, 0);
		else if (t == 3) ST.update(a, b, 0, k);
		else cout << ST.query(a, b) << '\n';
	}
}