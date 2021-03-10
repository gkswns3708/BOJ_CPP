#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long int

#define INF (1e9)+7

vector<int> vec;
int N, L;

bool possible() {
	int prefix_sum = 0;
	for (int i = N - 1; i > 0; i--) {
		prefix_sum += vec[i];
		int l = (vec[i - 1] - L) * (N - i);
		int r = (vec[i - 1] + L) * (N - i);
		if (l < prefix_sum && prefix_sum < r)continue;
		else return false;
	}
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	possible() == true ? cout << "stable" : cout << "unstable";
	
	return 0;
}