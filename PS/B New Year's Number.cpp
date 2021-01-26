#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		ll temp; cin >> temp;
		ll a = temp / 2020;
		ll b = temp % 2020;
		if (a < b) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}