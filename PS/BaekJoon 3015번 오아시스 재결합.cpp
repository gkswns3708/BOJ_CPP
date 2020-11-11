#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp; vec.push_back(temp);
	}
	ll ans = 0;
	stack<pair<int,int>> stk;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		while (!stk.empty() && stk.top().first < vec[i]) {
			ans += stk.top().second;
			stk.pop();
		}
		if (stk.empty()) {
			stk.push({ vec[i],1 });
		}
		else {
			if (stk.top().first == vec[i]) {
				int length = stk.top().second;
				ans += length;
				stk.pop();

				if (!stk.empty())ans++;
				
				stk.push({ vec[i],length+1 });
			}
			else {
				stk.push({ vec[i],1 });
				ans++;;
			}
		}
	}
	cout << ans;
	return 0;
}