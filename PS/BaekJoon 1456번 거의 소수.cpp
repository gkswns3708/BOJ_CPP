#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define int long long int
using namespace std;

vector<int> prime;
bool is_prime[11000000 + 1];
void linear_sieve() {
	for (int i = 2; i <= 11000000; ++i) {
		if (!is_prime[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] <= 11000000; ++j) {
			is_prime[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	linear_sieve();
	int st, ed; cin >> st >> ed;
	vector<int> vec;
	for (auto now : prime) {
		if (now > ed) break;
		int nxt = now;
		while (nxt <= ed) {
			if (nxt > LLONG_MAX / now) break;
			nxt *= now, vec.push_back(nxt);
		}
	}
	sort(vec.begin(), vec.end());
	st = lower_bound(vec.begin(), vec.end(), st) - vec.begin();
	ed = upper_bound(vec.begin(), vec.end(), ed) - vec.begin();
	cout << ed - st;

	return 0;
}
