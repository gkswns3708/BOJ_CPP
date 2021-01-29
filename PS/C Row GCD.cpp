#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll N, M; cin >> N >> M;
	vector<ll> a(N+1), b(M+1),d(N+1);
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= M; i++) cin >> b[i];
		
	for (int i = 1; i <= N; i++) 
		d[i] = a[i] - a[i - 1];
	
	ll res = 0;
	
	for (int i = 2; i <= N; i++) {
		res = gcd(res, d[i]);
	}
	
	for (int i = 1; i <= M; i++) 
		cout << abs(gcd(res, d[1] + b[i])) <<" ";
	return 0;
}