#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;



struct ST {
	vector<int> tree;
	int sz;
	ST(int N, vector<int>& vec) {
		int h = (int)ceil(log2(N));
		sz = 1LL << h;
		tree.resize(sz * 2);
		for (int i = 0; i < vec.size(); i++) tree[i + sz] = vec[i];
	}
	void update(int st, int ed, int node, int L, int R, int value) {
		if (ed < L || st > R) {
			return;//구간 밖이면 아무것도 안함. 
		}
		if (L <=st && ed <= R) {
			tree[node] ^= value; //구간 안이면 바로 XOR연산을 현재 노드에 취함.
			return;
		}
		int mid = (st + ed) / 2;
		update(st, mid, node * 2, L, R, value); //자식 L~mid
		update(mid+1, ed, node * 2 + 1, L, R, value);//mid+1~R까지 구간을 쪼개서 검사.
		//즉 현재 노드에서는 아무 행동 x
	}

	int query(int node) {
		node += sz;
		int ans = tree[node];
		while (node >>= 1) ans ^= tree[node];
		return ans;
	}
};


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> vec(N);
	for (auto& now : vec) cin >> now;
	ST st(N, vec);
	int M; cin >> M;
	while (M--) {
		int t, a, b, c;	cin >> t;
		if (t & 1) {
			cin >> a >> b >> c;
			st.update(0, st.sz-1, 1, a, b, c);
		}
		else {
			int a; cin >> a;
			cout << st.query(a) << "\n";
		}
	}
	return 0;
}