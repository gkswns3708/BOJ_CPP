#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#define INF 987654321
#define tiii tuple<int,int,int>
#define int long long int
using namespace std;
int N, M;
char arr[100+1][100 + 1];
int dist[100 + 1][100 + 1];
bool possible(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M) return true;
	else return false;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 cin >> M >> N;
	 for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
	
	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
	pq.push({ 0,0,0 });
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) dist[i][j] = INF;
	dist[0][0] = 0;	
	while (!pq.empty()) {
		auto [ndist, y, x] = pq.top();
		pq.pop();
		if (y == N - 1 && x == M - 1) {
			cout << ndist;
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			int dy = y + "1210"[i] - '1';
			int dx = x + "2101"[i] - '1';
			if (possible(dy,dx)) {
				int nxtdist = ndist + arr[dy][dx] - '0';
				if (dist[dy][dx] > nxtdist) {
					dist[dy][dx] = nxtdist;
					pq.push({ nxtdist,dy,dx });
				}
			}
		}
	}
	return 0;
}