#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<int,int>> vec;
bool check[100000 + 1];
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int TC; cin >> TC;
	while (TC--) {
		cin >> N;
		vec.clear();
		for (int i = 0; i < N; i++) {
			int v1, v2; cin >> v1 >>  v2;
			vec.push_back({ v1,v2 });
		}
		sort(vec.begin(), vec.end());
		int ans = N;
		int now = vec[0].second;
		for (int i = 1; i < N; i++) {
			//안되는 경우 일 때 전체--;
			if (vec[i].second > now) ans--;
			now = min(now, vec[i].second);
		}
		cout << ans <<"\n";
	}
	return 0;
}