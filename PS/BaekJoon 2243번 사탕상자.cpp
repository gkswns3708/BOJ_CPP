#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_Candy 1000000
using namespace std;
int N;
struct ST {
	vector<int> tree;
	int sz;
	ST(int& N) {
		cin >> N;
		sz = 1LL << (int)ceil(log2(MAX_Candy));
		tree.resize(sz * 2,0);
	}

	void update(int idx, int diff) {
		idx += sz - 1;
		do {
			tree[idx] += diff;
		} while (idx >>= 1);
	}

	int find(int node, int num) {
		if (node >= sz) {
			cout << node - sz + 1 << "\n";
			return node - sz + 1;//���� ��忡 ���� �ϸ� �ش� index�� return ��.
		}
		if (tree[node * 2] >= num) return find(node * 2, num);//40/30 < 17 �̸� ������ �� ū ���. �׷� �������� ������.
		else return find(node * 2 + 1, num-tree[node*2]);
	}
};


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ST st(N);
	while (N--) {
		int A, B, C; cin >> A;
		if (A & 1) {
			cin >> B;
			int pos = st.find(1, B);
			st.update(pos, -1);		
		}
		else {
			cin >> B >> C;
			st.update(B, C);
		}
	}

	return 0;
}