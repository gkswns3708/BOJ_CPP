#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int dist[50 + 1][50 + 1];
int arr[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int a, b;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) dist[i][j] = INF;
	while (cin >> a >> b && a != -1 && b != -1) dist[a][b] = dist[b][a] = 1;
	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF && i != j ) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int minvalue = INF;
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			arr[i] = max(arr[i], dist[i][j]);
		}
		if (minvalue > arr[i]) {
			minvalue = arr[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (minvalue == arr[i]) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	cout << arr[ans[0]] << " " << ans.size() <<"\n";
	for (auto now : ans) cout << now << " ";

	return 0;
}