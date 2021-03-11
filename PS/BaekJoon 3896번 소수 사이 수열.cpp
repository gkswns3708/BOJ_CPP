#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_prime[1400000 + 1];
vector<int> prime;
void linear_sieve() {
	for (int i = 2; i <= 1400000; ++i) {
		if (!is_prime[i]) prime.emplace_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] <= 1400000; ++j) {
			is_prime[i * prime[j]] = true;
			if (!(i % prime[j])) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	linear_sieve();
	while (TC--) {
		int k; cin >> k;
		bool flag = false;
		int ans = 0;
		for (int i = 0; i < prime.size()-1; i++) {
			if (k == prime[i]) break;
			else if (k > prime[i] && k < prime[i + 1]) 	ans = prime[i + 1] - prime[i];	
		}
		cout << ans << "\n";
	}

	return 0;
}