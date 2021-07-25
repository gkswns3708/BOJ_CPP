#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
vector<int> tree[500000 + 1];
struct ST {
	int sz, N;
	ST(int k) {
		cin >> N;
		sz = 1LL << (int)ceil(log2(N));
		for (int i = 1; i <= N;i++) {
			int now; cin >> now;
			update(1, sz, i, 1, now);//0~N-1±¸°£ 
		}
	}
	void update(int st, int ed, int node, int pos,int value) {
		if (node < st || ed < node) return;
		tree[pos].push_back(value);
		if (st != ed) {
			int mid = (st + ed)/2;
			update(st, mid, node, pos * 2, value);
			update(mid + 1, ed, node, pos * 2 + 1, value);
		}
	}
	int query(int st, int ed, int node, int L, int R, int value) {
		if (ed < L || R < st) return 0;
		if (L <= st && ed <= R) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
		int mid = (st + ed) / 2;
		return query(st, mid, node * 2, L, R, value) + query(mid + 1, ed, node * 2 + 1, L, R, value);
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ST st(1);
	int M; cin >> M;
	for (int i = 0; i < 500000 + 1; i++) sort(tree[i].begin(), tree[i].end());
	while (M--) {
		int i, j, k; cin >> i >> j >> k;
		cout << st.query(1, st.sz, 1, i, j, k) <<"\n";
	}
	return 0;
}