#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MOD 1000000007
using namespace std;

int N, M, K, sz = 1;
int arr[3000000 + 1];


int Mul(int L, int R, int nodeNum, int posL, int posR) {
	if (R < posL || L > posR) return 1;
	if (L <= posL && R >= posR) return arr[nodeNum];
	int mid = (posL + posR) / 2;
	return (Mul(L, R, nodeNum * 2, posL, mid) * Mul(L, R, nodeNum * 2 + 1, mid + 1, posR)) % MOD;
}

void construct() {
	for (int i = sz - 1; i > 0; i--) arr[i] = (min(arr[i * 2], arr[i * 2 + 1]))%MOD;
}

void Update(int idx, int value) {
	idx += sz;
	arr[idx] = value;
	while (idx > 1) {
		idx /= 2;
		arr[idx] = (arr[idx * 2] * arr[idx * 2 + 1]) % MOD;
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	while (sz < N) sz <<= 1;
	//arr + sz*2µµ °¡´É.
	fill(arr, arr + 3000000, 1);
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		arr[sz + i] = temp;
	}
	construct();

	for (int i = 0; i < M + K; i++) { 
		if (a == 1) Update(b - 1, c);
		else cout << Mul(b, c, 1, 1, sz) << "\n";
	}

	return 0;
}