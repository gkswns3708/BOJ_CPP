#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int arr[1000 + 1][1000 + 1];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	for (int i = 0; i <= 1000; i++) 
		for (int j = 0; j <= 1000; j++) {
			if (i == 0) arr[0][1] = 1;
			else if (j == 0) arr[1][0] = 1;
			else {
				int _gcd = gcd(i, j);
				int nowi = i / _gcd, nowj = j / _gcd;
				arr[nowi][nowj] = 1;
			}
		}
	
	while (TC--) {
		int N,cnt = 0; cin >> N;
		for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) cnt += arr[i][j];				
		cout << cnt << "\n";
	}

	return 0;
}