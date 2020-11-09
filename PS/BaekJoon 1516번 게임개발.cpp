#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N; cin >> N;
	int value[500 + 1] = { 0, };
	int ans[500 + 1] = { 0, };
	int num[500 + 1] = { 0, };
	bool visited[500 + 1] = { 0, };
	vector<vector<int>> vec(N+1);
	for (int i = 1; i <= N; i++) {
		//건물 가중치
		int val; cin >> val; value[i] = val;
		while (1) {
			int temp; cin >> temp;
			if (temp == -1) break;
			else {
				vec[temp].push_back(i);
				num[i]++;
			}
		}
	}
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (num[i] == 0) {
			que.push(i);
			ans[i] = value[i];
			visited[i] = true;
		}
		else {
			ans[i] = value[i];
		}
	}
	while (!que.empty()) {
		//nownum번째 건물을 만들었음.
		int nownum = que.front();
		//cout << "현재 고려중인 수 : " << nownum << "\n";
		que.pop();
		for (auto a : vec[nownum]) {
			ans[a] += value[nownum];
			num[a]--;
		}
		for (int i = 1; i <= N; i++) {
			if (num[i] == 0 && !visited[i]) {
				que.push(i);
				visited[i] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}