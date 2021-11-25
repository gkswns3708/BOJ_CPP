#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


int arr[1000000];
vector<int> min_tree;
void init(int node, int start, int end) {
    if (start == end) {
        min_tree[node] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    return;
}

int find(int node, int a, int b, int left, int right) {
    if (left > b || right < a) return 2147483647; 
    if (a <= left && right <= b) return min_tree[node];
    int l, r;
    int mid = (left + right) >> 1;
    l = find(node * 2, a, b, left, mid);
    r = find(node * 2 + 1, a, b, mid + 1, right);
    return min(l, r);
}

int segment(int x, vector<int> space) {
    if (x == 1) return *max_element(space.begin(), space.end());
    int sz = space.size();
    int size = 1 << int(ceil(log2(sz)) + 1);
    int ans = -INT_MAX;
    min_tree.resize(size);
    for (int i = 0; i < sz; ++i) arr[i] = space[i];
    init(1, 0, sz - 1);
    for (int i = 0; i < space.size(); ++i) {
        int from = i, to = i + x - 1;
        if (to >= sz) break;
        int tmp = find(1, i, i + x - 1, 1, sz);
        ans = max(ans, tmp);
    }
    return ans;
}
int main()