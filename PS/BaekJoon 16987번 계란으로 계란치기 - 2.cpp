#include <bits/stdc++.h>
#pragma warning(disable:4996)
#define INF 987654321
#define int long long int
#define X first
#define Y second

using namespace std;
using tiii = tuple<int, int, int>;
using pii = pair<int, int>;

vector<pair<int, int>> egg;
int N;
void input() {
	cin >> N;
	egg.resize(N);
	for (int i = 0; i < N; i++) cin >> egg[i].first >> egg[i].second;
}

int ans;

void DFS(int pos) {
	if (pos >= N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) if (egg[i].first <= 0) cnt++;
		ans = max(ans, cnt);
		return;
	}
	if (egg[pos].first <= 0) DFS(pos + 1);
	else {
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (i == pos || egg[i].first <= 0) continue;
			egg[i].first -= egg[pos].second;
			egg[pos].first -= egg[i].second;
			flag = true;
			DFS(pos + 1);
			egg[i].first += egg[pos].second;
			egg[pos].first += egg[i].second;
		}
		if (flag == false) DFS(N);
	}
}

void solution() {
	DFS(0);
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solution();
	return 0;
}