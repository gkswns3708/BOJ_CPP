#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[100000 + 1] = { 0, };
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a; arr[a]++;
	}
	vector<pair<int, int>> ans;
	for (int i = 1; i < N; i++) ans.push_back({ arr[i],i });
	sort(ans.begin(), ans.end());
	cout << ans[N - 4].second << "\n";
	return 0;
}