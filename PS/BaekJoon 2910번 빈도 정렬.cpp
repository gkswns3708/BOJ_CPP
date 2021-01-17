#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first == b.second.first) return a.second.second < b.second.second;
	else return  a.second.first > b.second.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	map<int, pair<int, int>> mp;
	int N, C; cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		int temp; cin >> temp;
		auto [cnt, pos] = mp[temp];
		mp[temp] = { ++cnt,		pos == 0 ? pos = i : pos };
	}
	vector<pair<int,pair<int, int>>> ans;
	for (auto a : mp) {
		auto [num, cnt] = a;
		ans.push_back({ num,cnt });
	}
	sort(ans.begin(), ans.end(), compare);
	for (auto a : ans) {
		for(int i = 0 ; i < a.second.first;i++) cout << a.first << " ";
	}
	
	return 0;
}