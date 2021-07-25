#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
int N;
struct ST {
	vector<int> A,B;
	vector<int> tree;
	int sz;
	ST(int &N) {
		cin >> N;
		A.resize(1000000+1);
		B.resize(N);
		for (int i = 0; i < N; i++) {
			int pos; cin >> pos;
			A[pos] = i;
		}
		for (int i = 0; i < N; i++) {
			int pos; cin >> pos;
			B[i] = A[pos];
		}
		sz = 1LL << (int)ceil(log2(N));
		tree.resize(sz * 2);
	}
	
	void update(int idx) {
		idx += sz;
		tree[idx]++;
		while (idx >>= 1) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}

	int query(int st, int ed, int node, int L,int R) {
		if (ed < L || R < st) return 0;
		if (L <= st && ed <= R) return tree[node];
		int mid = (st + ed) / 2;
		return query(st, mid, node * 2, L, R) + query(mid + 1, ed, node * 2 + 1, L, R);
	}
	void solution() {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans += query(0, sz - 1, 1, B[i], 1000000);
			update(B[i]);
		}
		cout << ans;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ST st(N);
	st.solution();
	return 0;
}