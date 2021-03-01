#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> ans;
int N;
void DP(int pos, int value) {
	if (pos == N) {
		ans.push_back(value);
		return;
	}
	else {
		DP(pos + 1, value);
		DP(pos + 1, value + vec[pos]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];

	ans.push_back(0);
	DP(0, 0);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	int pre = 0;
	bool check = false;
	for (int i = 1; i < ans.size(); i++) {
		if ((ans[i] - ans[i - 1]) > 1) {
			cout << ans[i - 1] + 1;
			check = 1;
			break;
		}
	}
	if (!check) cout << ans[ans.size() - 1] + 1;
	return 0;
}