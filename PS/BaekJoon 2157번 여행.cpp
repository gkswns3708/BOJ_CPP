#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

#define INF 987654321

int N, M,K;
int cost[300 + 1][300+1];
int dist[300 + 1][300 + 1];
vector<pair<int, int>> Edge[300 + 1];

int DP(int pos, int cnt) {
	if (pos == N) return 0;
	if (cnt == M) return -INF;
	int& ret = cost[pos][cnt];
	if (ret != -1) return ret;
	ret = -INF;
	for (int i = pos + 1; i <= N; i++) {
		if (dist[pos][i]) ret = max(ret, dist[pos][i] + DP(i, cnt + 1));
	}
	return ret;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int from, to, value; cin >> from >> to >> value;
		dist[from][to] = max(dist[from][to], value);
	}
	memset(cost, -1, sizeof(cost));
	int ans = DP(1, 1);
	ans == -1 ? cout << 0 : cout << ans;
	return 0;
}