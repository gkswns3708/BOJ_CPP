#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

typedef struct tree_node {
	int value = -1;
	tree_node* left;
	tree_node* right;
}tree_node;

vector<int> inorder_vec;
vector<int> postorder_vec;
tree_node* oldest_parent;

int N;

void make_tree(int inorder_start, int inorder_end, int postorder_start, int postorder_end,int direction, tree_node* parent) {
	int inorder_parent_index;
	
	if (inorder_start > inorder_end || postorder_start > postorder_end) return;

	tree_node* sub_parent = (tree_node*)malloc(sizeof(tree_node));
	sub_parent->left = nullptr;
	sub_parent->right = nullptr;
	sub_parent->value = postorder_vec.at(postorder_end);

	if (direction == 1) oldest_parent = sub_parent;
	else if (direction == 2) parent->left = sub_parent;
	else if (direction == 3) parent->right = sub_parent;

	if (inorder_start >= inorder_end) return;
	for (int i = inorder_start; i <= inorder_end; i++) {
		if (sub_parent->value == inorder_vec[i]) {
			inorder_parent_index = i;
			break;
		}
	}
	make_tree(inorder_parent_index + 1, inorder_end, postorder_end - (inorder_end - inorder_parent_index), postorder_end - 1, 3, sub_parent);
	make_tree(inorder_start, inorder_parent_index - 1, postorder_start, postorder_start + (inorder_parent_index - inorder_start) - 1, 2, sub_parent);
}

void make_preorder(tree_node* each_node) {
	if (each_node == NULL) return;
	cout << each_node->value << " ";
	make_preorder(each_node->left);
	make_preorder(each_node->right);
}

void input() {
	cin >> N;
	inorder_vec.resize(N), postorder_vec.resize(N);
	for (int i = 0; i < N; i++) cin >> inorder_vec[i];
	for (int i = 0; i < N; i++) cin >> postorder_vec[i];
}

void solution() {
	make_tree(0, N - 1, 0, N - 1, 1, NULL);
	make_preorder(oldest_parent);
}

int main() {
	fastio;
	input();
	solution();
}