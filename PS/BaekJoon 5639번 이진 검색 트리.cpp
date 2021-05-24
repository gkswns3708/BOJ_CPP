#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int now;
	vector<int> vec;
	while (cin >> now) vec.push_back(now);
	function <void(int, int)> PostOrder = [&](int st, int ed) ->void {
		if (st == ed) return;
		if (st == ed - 1) {
			cout << vec[st] << "\n";
			return;
		}
		int idx = st + 1;;
		while (1) {
			if ((idx < ed && vec[idx] < vec[st]) == false) break;
			idx++;
		}
		PostOrder(st + 1, idx);
		PostOrder(idx, ed);
		cout << vec[st] << "\n";
	};
	PostOrder(0, vec.size());
	return 0;
}