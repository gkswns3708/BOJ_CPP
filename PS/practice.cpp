#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void Update_lazy(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end) {
	if (lazy[node] == 0) 
		return;

	tree[node] += (end - start + 1) * lazy[node];

	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;
}

void Update_range(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right, ll val) {

	Update_lazy(tree, lazy, node, start, end);

	if (left > end || right < start)
		return;

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * val;

		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	Update_range(tree, lazy, node * 2, start, mid, left, right, val);
	Update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right) {
	Update_lazy(tree, lazy, node, start, end);

	if (left > end || right < start) 
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, lazy, node*2, start, mid, left, right) + sum(tree, lazy, node*2+1, mid + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector<ll> arr(N);
	vector<ll> tree(tree_size);
	vector<ll> lazy(tree_size);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, N - 1);
	M += K;
	while (M--) {
		int num;
		cin >> num;
		if (num == 1) {
			int left, right;
			ll val;

			cin >> left >> right >> val;
			Update_range(tree, lazy, 1, 0, N - 1, left - 1, right - 1, val);
		}

		else if (num == 2) {
			int left, right;
			cin >> left >> right;
			cout << sum(tree, lazy, 1, 0, N - 1, left - 1, right - 1)<<"\n";
		}
	}
	return 0;
}
