#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

struct ST {
	vector<int> tree;
	int sz;
	ST(int n, vector<int>& arr) {
		int h = (int)ceil(log2(n));
		sz = 1LL << h;
		tree.resize(sz << 1);
		for (int i = 0; i < arr.size(); i++) tree[i + sz] = arr[i];
		for (int i = --sz ; i >= 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	void update(int i, int x) {
		int node = i + sz;
		tree[node] += x;
		while (node >>= 1) tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}
	int query(int x) {
		int i = 1;
		while (i <= sz) {
			int l = tree[i << 1], r = tree[i << 1 | 1];
			if (l >= x) i <<= 1;//왼쪽에 있는 경우
			else i = i << 1 | 1, x -= l; //i가 오른쪽으로 가고 x는 원래 왼쪽의 사람들 만큼 빠짐.
		}
		return i - sz;
	}
};



int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	ST st(N, vec);
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (a & 1) {
			int c; cin >> c;
			st.update(b, c);
		}
		else cout << st.query(b) << "\n";
	}
	return 0;
}