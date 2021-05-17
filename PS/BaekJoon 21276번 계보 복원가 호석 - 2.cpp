#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> nametonum;
unordered_map<int, string> numtoname;
vector<int> edge[1000 + 1];
vector<int> child[1000 + 1];
int level[1000 + 1];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		nametonum[s] = i;
		numtoname[i] = s;
	}
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		string from, to; cin >> from >> to;
		level[nametonum[from]]++;
		edge[nametonum[to]].push_back(nametonum[from]);
	}
	vector<string> root;
	queue<int> que;
	for (int i = 1; i <= N; i++) if (!level[i]) que.push(i),root.push_back(numtoname[i]);

	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		for (auto nxt : edge[now]) 	if (--level[nxt] == 0)que.push(nxt), child[now].push_back(nxt);
	}

	sort(root.begin(), root.end());
	cout << root.size() << "\n";
	for (auto now : root) cout << now << " ";cout << "\n";
	vector<string> ans;
	for (int i = 1; i <= N; i++) ans.push_back(numtoname[i]);
	sort(ans.begin(), ans.end());
	for (auto now : ans) {
		cout << now <<' '<< child[nametonum[now]].size() << ' ';
		vector<string> temp;
		for (auto nxt : child[nametonum[now]])temp.push_back(numtoname[nxt]);
		sort(temp.begin(), temp.end());
		for (auto nxt : temp) cout << nxt << " ";
		cout << '\n';
	}
	return 0;
}