#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#pragma once
using namespace std;
typedef long long int ll;

bool compare(int a, int b) { 
	return a < b; 
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int n, m; cin >> n >> m;
		vector<pair<int, int>> pii(n + 1);
		vector<int> vec1(n + 1);
		vector<int> vec2(n + 1),p1(1,0), p2(1,0);
		for (int i = 0; i < n; i++) cin >> pii[i].first;
		for (int i = 0; i < n; i++) cin >> pii[i].second;
		for (auto a : pii) {
			if (a.second == 1) vec1.push_back(a.first);
			else vec2.push_back(a.first);
		}
		sort(vec1.begin(), vec1.end(), greater<int>() );
		sort(vec2.begin(), vec2.end(), greater<int>());
		if (!vec1.empty()) {
			for (auto a : vec1)
				p1.push_back(a);
		}
		if (!vec2.empty()) {
			for (auto a : vec2)
				p2.push_back(a);
		}
		//누적합으로 구하기.
		for (int i = 1; i < p1.size(); i++) {
			p1[i] += p1[i - 1];
		}
		for (int i = 1; i < p2.size(); i++) {
			p2[i] += p2[i - 1];
		}
		int sz1 = vec1.size();
		int ans = 987654321;
		for (int i = 0; i < sz1 + 1; i++) {
			int rm = m - p1[i];
			if (rm <= 0)ans = min(ans, i);
			int pos = lower_bound(p2.begin(), p2.end(), rm) - p2.begin();
			if (pos == p2.size()) --pos;
			rm -= p2[pos];
			if (rm <= 0)ans = min(ans, i + 2 * pos);
		}
		if (ans == 987654321)ans = -1;
		cout << ans << "\n";
	}
	return 0;
}