#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	int arr[100000 + 1] = { 0, };
	while (cin >> N) {
		int len = 0;
		for (int i = 0; i < N; i++) {
			int val; cin >> val;
			int* pos = lower_bound(arr, arr + len, val);
			*pos = val;
			len += pos == arr + len;
		}
		cout << len << '\n';
		fill(arr, arr + len, 0);
	}
	return 0;
}