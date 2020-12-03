#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define MAX 10010

int V, E, cnt, dfsn[MAX], SCCtotal, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC가 확정된 정점 판별
stack<int> s;
vector<vector<int>> SCC;

int dfs(int curr) {
	dfsn[curr] = ++cnt;
	s.push(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0)
			result = min(result, dfs(next));
		else if (!finished[next])
			result = min(result, dfsn[next]);
	}
	if (result == dfsn[curr]) {
		vector<int> curSCC;
		while (1) {
			int t = s.top();
			s.pop();
			curSCC.push_back(t);
			finished[t] = true;
			sn[t] = SCCtotal;

			if (t == curr)
				break;
		}

		sort(curSCC.begin(), curSCC.end());
		SCC.push_back(curSCC);
		SCCtotal++;
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to; cin >> from >> to;
		adj[from].push_back(to);
	}

	for (int i = 1; i <= V; i++) {
		if (dfsn[i] == 0)
			dfs(i);
	}

	sort(SCC.begin(), SCC.end());
	cout << SCCtotal << "\n";


	for (auto& currSCC : SCC) {
		for (int curr : currSCC)
			cout << curr << " ";

		cout << "-1" << "\n";
	}
	return 0;
}