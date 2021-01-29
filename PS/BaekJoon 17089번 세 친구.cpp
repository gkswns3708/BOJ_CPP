#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M;
bool visited[4000 + 1][4000 + 1];
int num[4000 + 1];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to; cin >> from >> to;
		visited[from][to] = true,visited[to][from] = true;
		num[from]++,num[to]++;
	}
}

void solution() {
	int ans = 987654321;
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if(visited[i][j])
			for (int k = j + 1; k <= N; k++) {
				if (visited[j][k] && visited[i][k]) {
					flag = false;
					ans = min(ans, num[i] + num[j] + num[k] - 6);
				}
			}
		}
	}
	if (flag) cout << -1;
	else cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}