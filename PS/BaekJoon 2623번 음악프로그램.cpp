#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> vec(N+1);
	bool visited[1000 + 1] = { 0, };
	int arr[1000 + 1] = { 0, };
	for (int TC = 0; TC < M; TC++) {
		int K, temp; cin >> K >> temp;
		for (int i = 1; i < K; i++) {
			int nownum; cin >> nownum;
			vec[temp].push_back(nownum);
			arr[nownum]++;
			temp = nownum;
		}
	}
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			que.push(i);
			visited[i] = true;
		}
	}
	vector<int> ans;
	while (!que.empty()) {
		int nownum = que.front();
		ans.push_back(nownum);
		que.pop();
		for (auto a : vec[nownum]) {
			arr[a]--;
		}
		for (int i = 1; i <= N; i++) {
			if (arr[i] == 0 && visited[i] == false) {
				que.push(i);
				visited[i] = true;
			}
		}
	}
	if (ans.size() == N) {
		for (auto a : ans)
			cout << a << "\n";
	}
	else cout << 0;
	return 0;
}