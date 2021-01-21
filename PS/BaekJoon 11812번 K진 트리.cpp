#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N, K, Q;

void input() {
	cin >> N >> K >> Q;
}

void solution() {
	for (int i = 0; i < Q; i++) {
		ll num1, num2; cin >> num1 >> num2;
		ll ans = 0;
		if (K == 1) cout << abs(num1 - num2) <<"\n";
		else {
			while (num1 != num2) {
				if (num1 > num2) num1 = (num1 - 2) / K + 1;
				else num2 = (num2 - 2) / K + 1;
				ans++;				
			}
			cout << ans <<"\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}