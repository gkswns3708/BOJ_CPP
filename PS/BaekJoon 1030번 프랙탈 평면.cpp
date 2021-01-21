#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int s, N, K, R1, R2, C1, C2;
int length;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
	length = pow(3, N);
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			int b = 0;
			for (int x = i, y = j; x; x /= N, y /= N) 
				if (b |= x % N * 2 >= N - K && x % N * 2 < N + K && y % N * 2 >= N - K && y % N * 2 < N + K) break;				
			cout << b;
		}
		cout << "\n";
	}
	return 0;
}
