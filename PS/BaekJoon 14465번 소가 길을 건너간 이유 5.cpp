#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

bool visited[100000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K, B, length = 0, sum = 0, ans = 987654321; cin >> N >> K >> B;
	vector<int> ps;
	queue<int> que;
	for (int i = 0; i < B; i++) {
		int a; cin >> a;
		visited[a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) ps.push_back(length), length = 0;
		else length++;
	}
	ps.push_back(length);
	for (auto now : ps) {
		sum += now;
		que.push(now);
		while (sum +int(que.size()) -1 >= K && !que.empty()) {
			ans = min(ans, int(que.size())-1);
			auto front = que.front();
			sum -= front;
			que.pop();
		}
	}
	cout << ans;
	return 0;
}