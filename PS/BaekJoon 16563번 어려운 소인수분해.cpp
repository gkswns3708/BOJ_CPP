#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int sz = int(5e6);

int sieve[5000000 + 1];
vector<int> p;
void linear_sieve(int n = sz){
	for (int i = 2; i <= n; i++) {
		if (!sieve[i]) p.push_back(i);
		for (auto j : p) {
			if (i * j > n) break;
			sieve[i * j] = j;
			if (i % j == 0) break;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	linear_sieve();
	int n; cin >> n;
	while (n--)	{
		int i; cin >> i;
		while (sieve[i]) cout << sieve[i] << ' ',i /= sieve[i];
		cout << i << '\n';
	}
}