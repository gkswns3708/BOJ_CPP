#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		vector<string> vec(N),vec1(N),vec2(N);
		map<pair<string,int>, string> mp1;
		map<string, pair<string, int>> mp2;
		vector<int> pos(N);
		vector<string> ans(N);
		for (int i = 0; i < N; i++) cin >> vec[i];
		for (int i = 0; i < N; i++) cin >> vec1[i];
		for (int i = 0; i < N; i++) cin >> vec2[i];
		for (int i = 0; i < N; i++) {
			mp1[{vec2[i], i}] = vec1[i];
			mp2[vec1[i]] = { vec2[i],i };
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			if (vec[i] == vec1[j]) {
				ans[i] = mp2[vec1[j]].first;
				break;
			}
		}
		for (auto now : ans) cout << now << " ";
		cout << "\n";
	}
	return 0;
}