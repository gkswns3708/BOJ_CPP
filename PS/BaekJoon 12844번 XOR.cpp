#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) ^ init(arr, tree, node * 2 + 1, mid + 1, end);
}

void Update_lazy(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] ^= lazy[node] * ((end - start + 1) % 2);
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

int Update_range(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right, ll val) {
	Update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start)
		return tree[node];
	if (left <= start && end <= right) {
		tree[node] ^= val * ((end - start + 1) % 2);
		if (start != end) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return tree[node];
	}
	int mid = (start + end) / 2;
	return tree[node] = Update_range(tree, lazy, node * 2, start, mid, left, right, val) ^ Update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);
}

ll X_or(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right) {
	Update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return X_or(tree, lazy, node * 2, start, mid, left, right) ^ X_or(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int h = (int)ceil(log2(N)) + 1;
	int tree_size = 1 << h;

	vector<ll> arr(N);
	vector<ll> tree(tree_size);
	vector<ll> lazy(tree_size);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, N - 1);
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			int left, right;
			ll val;
			cin >> left >> right >> val;
			if (left > right) swap(left, right);
			Update_range(tree, lazy, 1, 0, N - 1, left, right, val);
		}

		else if (num == 2) {
			int left, right;
			cin >> left >> right;
			if (left > right) swap(left, right);
			cout << X_or(tree, lazy, 1, 0, N - 1, left, right) << "\n";
		}
	}
	return 0;
}
