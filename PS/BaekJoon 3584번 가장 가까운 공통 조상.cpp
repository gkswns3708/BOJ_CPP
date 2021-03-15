#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <queue>
#define int long long int
using namespace std;

int N,root;
vector<int> edge[10000 + 1];
int par[10000 + 1];
bool visited[10000 + 1];
int level[10000 + 1];


void make_level(int root) {
	memset(visited, 0, sizeof(visited));
	queue<int> que;
	int lev = 0;
	que.push(root);
	visited[root] = 1;
	while (!que.empty()) {
		int size = que.size();
		lev++;
		while (size--) {
			int now = que.front();
			que.pop();
			for (auto nxt : edge[now]) {
				if (!visited[nxt]) {
					level[nxt] = lev;
					visited[nxt] = 1;
					que.push(nxt);
				}
			}
		}
	}
}

int cal(int a, int b) {
	while (level[a] != level[b]) {
		if (level[a] > level[b]) a = par[a];
		else b = par[b];
	}
	while (a != b) {
		a = par[a];
		b = par[b];
	}
	return a;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		cin >> N;
		memset(visited, 0, sizeof(visited));
		memset(level, 0, sizeof(level));
		for (int i = 1; i <= N; i++) edge[i].clear();
		for (int i = 1; i < N; i++) {
			int parents, child; cin >> parents >> child;
			visited[child] = 1;
			par[child] = parents;
			edge[child].push_back(parents);
			edge[parents].push_back(child);
		}
		for (int i = 1; i <= N; i++) if (!visited[i]) root = i;
		make_level(root);
		int a, b; cin >> a >> b;
		cout <<cal(a, b) <<"\n";
	}
	return 0;
}