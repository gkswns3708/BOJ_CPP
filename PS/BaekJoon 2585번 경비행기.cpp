#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long int
using namespace std;

int dist[1000 + 100][1000 + 10];

int cal(pair<int, int> a, pair<int, int> b) {
	int x = a.first - b.first;
	int y = (a.second - b.second);
	return abs(x * x - y * y);
}

bool Dijkstra() {

}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;
	vector<pair<int, int>> pos(N+1);
	for (int i = 1; i <= N; i++) cin >> pos[i].first >> pos[i].second;
	//ÀüÃ³¸®
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			dist[i][j] = cal(pos[i], pos[j]);
		
	



	return 0;
}