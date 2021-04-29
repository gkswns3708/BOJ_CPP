#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long int
#define INF 987654321
using namespace std;

pii nd[10000 + 1];
pii ans[10000 + 1];
int maxheight = 0;
bool visited[10000 + 1];
vector<pii> pos;
int root, N, ps = 1, maxgap = 0, maxlevel = 1;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	pos.resize(N + 1);
	for (int i = 1; i <= N; i++) ans[i].first = INF,ans[i].second = 0;
	for (int i = 0; i < N; i++) {
		int parents, left, right; cin >> parents >> left >> right;
		if(left != -1) nd[parents].second = left, visited[left] = 1;
		if(right != -1) nd[parents].first = right, visited[right] = 1;
	}

	auto BFS = [&](int root) {
		queue<int> que;
		que.push(root);
		int height = 1;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				auto now = que.front();
				pos[now].first = height;
				que.pop();
				if (nd[now].second != 0) que.push(nd[now].second);
				if (nd[now].first != 0) que.push(nd[now].first);
			}
			height++;
		}
	};

	for (int i = 1; i <= N; i++) if (!visited[i]) root = i;
	BFS(root);
	function <void(int)> preorder = [&](int root)->void {
		if (nd[root].second != 0) preorder(nd[root].second);
		pos[root].second = ps++;
		if (nd[root].first != 0) preorder(nd[root].first);
	};

	preorder(root);

	sort(pos.begin(), pos.end());
	for (int i = 1; i <= N; i++) {
		ans[pos[i].first].first = min(ans[pos[i].first].first, pos[i].second);
		ans[pos[i].first].second = max(ans[pos[i].first].second, pos[i].second);
	}

	for (int i = 1; i <= N; i++) if (maxgap < ans[i].second - ans[i].first) maxgap = ans[i].second - ans[i].first,maxlevel = i;
		
	cout << maxlevel << " " << maxgap+1;
	return 0;
}