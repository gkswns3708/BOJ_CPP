#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp; vec.push_back(temp);
	}
	stack<int> stk;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		while (!stk.empty() && stk.top() <= vec[i])stk.pop();
		ans +=stk.size();
		stk.push(vec[i]);
	}
	cout << ans;
	return 0;
}