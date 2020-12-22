#pragma once
#include <bits/stdc++.h>
#define MAX_V 10000
using namespace std;
int v, e, discover[MAX_V + 1], x, y, r, c, scc[MAX_V + 1];
stack<int> st;
vector<vector<int>> vt;
vector<vector<int>> res;
bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int dfs(int here) {
	discover[here] = c++;
	int ret = discover[here];
	st.push(here);
	for (int there : vt[here]) {
		if (discover[there] == -1)
			ret = min(ret, dfs(there));
		else if (scc[there] == -1)
			ret = min(ret, discover[there]);
	}
	if (ret == discover[here]) {
		vector<int> tmp;
		while (1) {
			int t = st.top();
			st.pop();
			scc[t] = r;
			tmp.push_back(t);
			if (t == here) break;
		}
		sort(tmp.begin(), tmp.end());
		res.push_back(tmp);
		r++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	vt.resize(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		vt[x].push_back(y);
	}
	memset(discover, -1, sizeof(discover));
	memset(scc, -1, sizeof(scc));
	for (int i = 1; i <= v; i++) {
		if (discover[i] == -1)
			dfs(i);
	}
	sort(res.begin(), res.end(), cmp);
	cout << r << "\n";
	for (int i = 0; i < r; i++) {
		for (auto h : res[i])
			cout << h << " ";
		cout << -1 << "\n";
	}
	return 0;
}