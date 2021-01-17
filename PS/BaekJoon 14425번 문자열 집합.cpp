#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	map<string, int> mp;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		mp[s]++;
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string temp; cin >> temp;
		if (mp[temp] >= 1) cnt++;
	}
	cout << cnt;
	return 0;
}