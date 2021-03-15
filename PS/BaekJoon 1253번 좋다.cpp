#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
#define int long long int

int arr[2001];
map<int, pair<bool,int> > mp;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mp[arr[i]] = { false,i };
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int now = arr[i] + arr[j];		
			if (mp.find(now)!=mp.end()) {
				if (mp[now].second != i && mp[now].second != j )mp[now].first = true;

			}
		}
	}


	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (mp[arr[i]].first == true)ans++;
	}
	cout << ans;
	return 0;
}