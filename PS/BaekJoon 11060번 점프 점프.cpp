#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	vector<int> dist(N + 1,INF);
	dist[0] = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j + i < N && j <= vec[i]; j++) 
			dist[j + i] = min(dist[j + i], dist[i] + 1);
		
	
	dist[N - 1] == INF ? cout << -1 : cout << dist[N - 1];
	return 0;
}