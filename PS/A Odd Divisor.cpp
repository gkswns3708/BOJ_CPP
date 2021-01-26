#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		ll N; cin >> N;
		bool check;
		while (1) {
			if (N == 1) {
				check = false;
				break;
			}
			else if (N % 2 == 1) {
				check = true;
				break;
			}
			N /= 2;
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}