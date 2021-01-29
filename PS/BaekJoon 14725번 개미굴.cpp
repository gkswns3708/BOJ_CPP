#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define X first
#define Y second
#define INF 987654321

struct Node {
	map<string, Node> child;
};
Node root;
void insert(Node& root, vector<string>& v, int idx)
{
	if (idx == v.size())return;

	if (!root.child.count(v[idx]))
		root.child[v[idx]] = Node();
	insert(root.child[v[idx]], v, idx + 1);
}

void dfs(Node& root, int dep)
{
	for (auto i : root.child)
	{
		for (int j = 0; j < dep; j++)
			cout << "--";
		cout << i.first << "\n";
		dfs(i.second, dep + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int M; cin >> M;
		vector<string> v(M);
		for (int j = 0; j < M; j++) {
			cin >> v[j];
		}
		insert(root,v, 0);
	}

	dfs(root, 0);
	return 0;
}