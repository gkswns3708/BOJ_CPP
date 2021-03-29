#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define int long long int
using namespace std;

vector<int> prime;
bool is_prime[1000000 + 1];
void linear_sieve() {
	for (int i = 2; i <= 1000000; ++i) {
		if (!is_prime[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] <= 1000000; ++j) {
			is_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int arr[1000000 + 1];
int sangun[1000000 + 1];
map<int, int> mp;

int checkcycle(int num) {
	if (sangun[num]) return sangun[num];
	else if (mp[num]) return 2;
	else if (num == 1) return 1;
	else {
		mp[num]++;
		sangun[num] = checkcycle(arr[num]);
		return sangun[num];
	}	
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	linear_sieve();
	int n; cin >> n;
	for (int i = 1; i <= 1000000;  ++i) {
		string s = to_string(i);
		int nxt = 0;
		for (auto now : s) 	nxt += (now - '0') * (now - '0');
		arr[i] = nxt;
	}
	int ans = 0;
	sangun[1] = 1;
	for (int i = 2; i <= n; ++i) {
		mp.clear();
		if (checkcycle(i) == 1 && !is_prime[i]) cout << i << "\n";
	}
	return 0;
}