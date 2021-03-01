#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

ll a, b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >>a  >> b && (a != 0 &&b  != 0))  {
		ll ans = 1, div = 1;
		b = min(b, a - b);
		while (b--) {
			ans *= a--;
			ans /= div++;
		}
		cout << ans << "\n";
		}
	return 0;
}