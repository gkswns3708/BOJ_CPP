#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long int ll;

ll arr[3000000 + 1];
int SIZE = 1;
int N, M, K;
ll sum(ll L, ll R, ll nodeNum, ll nodeL, ll nodeR) {
	if (R<nodeL || L >nodeR) return 0;
	if (L <= nodeL && R >= nodeR) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

void Update(ll i, ll value) {
	arr[i] = value;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}

//트리를 만들어줌.
void construct() {
	for (int i = SIZE - 1; i > 0; i--) {
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}

int main() {
	fastio;
	cin >> N >> M >> K;
	int num;
	ll h = (ll)ceil(log2(N));
	SIZE = 1 << (h);


	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[SIZE + i] = num;
	}
	construct();

	ll a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			Update(b - 1 + SIZE, c);
		}
		else {
			cout << sum(b, c, 1, 1, SIZE) << '\n';
		}
	}

	return 0;
}