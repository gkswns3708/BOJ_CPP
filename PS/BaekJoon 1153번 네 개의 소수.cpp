#include <bits/stdc++.h>
using namespace std;

bool is_prime[1000000 + 1];
vector<int> prime;
void linear_sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!is_prime[i]) prime.push_back(i);
		for (auto now : prime) {
			if (now * i > n)break;
			is_prime[i*now] = true;
		}
	}
}

int32_t main() {
	int N; cin >> N;
	linear_sieve(N);
	if (N < 8) return !printf("-1");
	else if (N == 8) return !printf("2 2 2 2");
	else if (N%2) N -= 5, printf("2 3 ");
	else N -= 4, printf("2 2 ");
	for (int i = 2; i < N; i++) if (!is_prime[i] && !is_prime[N - i])return !printf("%d %d", i, N - i);
}