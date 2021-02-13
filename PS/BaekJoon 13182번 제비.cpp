#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int ll;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

ll R, G, B, K;

ll ipow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

void input() {
	int TC; cin >> TC;
	while (TC--) {
		cin >> R >> G >> B >> K;
		ll a = ((ipow(1 + B, K) * (B * K % MOD + R * B % MOD + G * K % MOD))% MOD - R *ipow(B, K+1)) % MOD;
		ll b = (ipow(1 + B, K) * B)%MOD;
		ll ans = (a * ipow(b, MOD - 2)) % MOD;
		ans < 0 ? ans += MOD : 1;
		cout << ans<<"\n";
	}
}

int main() {
	fastio;
	input();
}