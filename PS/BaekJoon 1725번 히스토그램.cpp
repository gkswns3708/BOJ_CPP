#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int arr[100000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int h = arr[st.top()];
			int w = i;
			st.pop();
			if (!st.empty()) w = i - st.top() - 1;
			ans = max(ans, h * w);
		}
		st.push(i);
	}
	while (!st.empty()) {
		int h = arr[st.top()];
		int w = N;
		st.pop();
		if (!st.empty())w = N - st.top() - 1;
		ans = max(ans, h * w);
	}
	cout << ans;
	return 0;
}