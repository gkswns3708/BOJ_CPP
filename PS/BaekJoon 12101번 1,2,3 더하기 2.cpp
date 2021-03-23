#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long int
using namespace std;

int n, k;
int cnt;
void dfs(int sum,vector<int>& vec) {
	if (sum > n) return;
	if (sum == n) {
		cnt++;
		if (cnt == k) {
			string s = "";
			for (auto now : vec) {
				s +=to_string(now);
				s += '+';
			}
			s.pop_back();
			cout << s;
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		vec.push_back(i);
		dfs(sum + i, vec);
		vec.pop_back();
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	vector<int> v;
	dfs(0,v);
	if (cnt < k) cout << -1;
	return 0;
}