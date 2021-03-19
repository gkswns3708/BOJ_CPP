#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long int
#define pii pair<int,int>
using namespace std;

int N, L,K;

vector<int> edge[200000 + 1];
vector<int> dist(100000 + 100000 + 2,-1);
bool visited[200000 + 2];

int sol(int st, int ed) {
	queue<int> que;
	dist[st] = 0;
	visited[1] = true;
	que.push(st);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (now == N) break;
		for (auto nxt : edge[now]) {
			if (!visited[nxt]) {
				visited[nxt] = 1;
				dist[nxt] = dist[now] + 1;
				que.push(nxt);
			}
		}
	}
	if (N != 1 && dist[ed] == -1) return -1;
	else return dist[ed]/2 + 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> L;
	for (int i = 1; i <= L; i++) {
		for (int j = 0; j < K; j++) {
			int now; cin >> now;
			edge[N + i].push_back(now);
			edge[now].push_back( N + i);
		}
	}
	cout << sol(1, N);
	return 0;
}