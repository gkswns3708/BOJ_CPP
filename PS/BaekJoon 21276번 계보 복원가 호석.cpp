#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int level[1000 + 1];
unordered_map<string, int> nameidx;
unordered_map<int, string> idxname;
vector<pair<string, string>> order;
vector<string> root;
vector<string> ans;
vector<int> parents[1000 + 1];
vector<int> edge[1000 + 1];
vector<int> child[1000 + 1];
queue<int> que;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		nameidx[s] = i;
		idxname[i] = s;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string a, b; cin >> a >> b;
		level[nameidx[a]]++;
		parents[nameidx[b]].push_back(nameidx[a]);
	}
	for (int i = 0; i < N; i++) if (!level[i]) que.push(i),root.push_back(idxname[i]);
	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		for (auto nxt : parents[now]) if (--level[nxt] == 0) que.push(nxt), child[now].push_back(nxt);
	}
	//Ãâ·Â
	sort(root.begin(), root.end());
	ans.resize(N);
	for (int i = 0; i < N; i++) ans[i] = idxname[i];

	sort(ans.begin(), ans.end());cout << root.size() <<"\n";
	for (auto now : root)cout << now << " "; cout << '\n';
	for (auto now : ans) {
		cout << now << " " << child[nameidx[now]].size() << " ";
		vector<string> temp;
		for (auto nxt : child[nameidx[now]]) temp.push_back(idxname[nxt]);
		sort(temp.begin(), temp.end());
		for (auto nxt : temp) cout << nxt << " ";cout << "\n";
	}
	return 0;
}