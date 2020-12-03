#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	map<string, string> mp;
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s1, s2; cin >> s1 >> s2;
		mp.insert({ s1,s2 });
	}
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		cout << mp[s] << "\n";
	}
	return 0;
}