#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;


struct SEG {
    int N, K, SIZE;
    vector<int> tree;
    void input() {
        cin >> N >> K;
        SIZE = 1LL << (int)ceil(log2(N));
        tree.resize(SIZE * 2);
    }

    int init(int l, int r, int node) {
        if (l == r) return tree[node] = 1;
        int mid = (l + r) / 2;
        return tree[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
    }

    int query(int node, int l, int r, int cnt) {
        tree[node]--;
        if (l == r) return l;

        int mid = (l + r) / 2;
        if (cnt <= tree[node * 2]) return query(node * 2, l, mid, cnt);
        else return query(node * 2 + 1, mid + 1, r, cnt - tree[node * 2]);
    }
};


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SEG seg;
    seg.input();
    seg.init(1, seg.N, 1);
    int idx = seg.K - 1;
    cout << "<";
    for (int i = 1; i <= seg.N; i++) {
        int new_idx = seg.query(1, 1, seg.N, idx + 1);

        if (i != seg.N) cout << new_idx << ", ";
        else cout << new_idx;

        if (seg.tree[1] == 0) break;

        idx += seg.K - 1;
        idx %= seg.tree[1];
    }
    cout << ">";

    return 0;
}