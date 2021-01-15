#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int N; cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	ll ans = 0;
	if (vec[0] != 1) {
		ans += vec[0] - 1;
		vec[0] = 1;
	}
	for (int i = 1; i < N; i++) {
		if (vec[i] > vec[i - 1]) {
			ans += vec[i] - (vec[i - 1] + 1);
			vec[i] = vec[i - 1] + 1;
		}
	}
	cout << ans;
	return 0;
}