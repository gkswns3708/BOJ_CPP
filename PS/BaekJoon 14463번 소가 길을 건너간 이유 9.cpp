#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

struct ST {
	vector<int> tree;
	int sz;
	ST(int N) {
		int h = (int)ceil(log2(2*N));
		sz = 1LL << h;
		tree.resize(sz * 2);
		sz--;
	}
	void update(int idx) {
		int node = idx + sz;
		tree[node]++;
		while (node >>= 1) 	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	int query(int st, int ed, int node, int L, int R) {
		if (ed < L || st > R) return 0;
		if (L <= st && ed <= R) return tree[node];
		int mid = (st + ed) / 2;
		return query(st, mid, node * 2, L, R) + query(mid + 1, ed, node * 2 + 1, L, R);
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<pii> vec(N + 1, { -1,-1 });
	for (int i = 1; i <= 2 * N; i++) {
		int now; cin >> now;
		if (vec[now].first == -1) vec[now].first = i;
		else vec[now].second = i;
	}
	sort(vec.begin() + 1, vec.end());
	int ans = 0;
	ST st(N);
	for (int i = 1; i <= N; i++) {
		ans += st.query(1, st.sz+1, 1, 1, vec[i].second) - st.query(1, st.sz + 1, 1, 1, vec[i].first);
		st.update(vec[i].second);
	}
	cout << ans << "\n";
	return 0;
}