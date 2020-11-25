#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int month[13] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
	vector<pair<int, int>> date;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (a == c && b == d) {
			N--;
			continue;
		}
		date.push_back({ month[a] + b,month[c] + d});
	}
	sort(date.begin(), date.end());
	int limitday = 60;
	vector<pair<int, int>> vec;
	for (int i = 0; i < N;) {
		bool check = true;
		vector<pair<int, int>> tempvec;
		while (i < N && date[i].first <= limitday) {
			tempvec.push_back(date[i++]);
			check = false;
		}
		sort(tempvec.begin(), tempvec.end(), compare);
		if (!tempvec.empty()) {
			vec.push_back(tempvec.front());
			limitday = tempvec.front().second;
		}
		if (!vec.empty() && vec.back().second > 334) break;
		if (check) i++;
	}
	if (vec.empty()  || vec.back().second <= 334) cout << 0;
	else cout << vec.size();

	return 0;
}