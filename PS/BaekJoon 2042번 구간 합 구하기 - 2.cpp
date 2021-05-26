#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int arr[2100000 + 1];
int sz = 1;
int N, M, K,num;

//target 구간 L, target 구간 R, 현재 위치, 현재 확인 구간L(posL), 현재 확인구간R(posR)
int sum(int L, int R, int nodeNum, int posL, int posR) {
	if (R < posL || L > posR) return 0;
	if (L <= posL && R >= posR) return arr[nodeNum];
	int mid = (posL + posR) / 2;
	return sum(L, R, nodeNum * 2, posL, mid) + sum(L, R, nodeNum * 2+1, mid + 1, posR);
}


void Update(int i, int value) {
	arr[i] = value;
	while (i > 1) i /= 2,arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void construct() {
	//자식 노드를 이용해 부모노드의 값을 갱신함.
	for (int i = sz - 1; i >= 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	while (sz < N) sz <<= 1; 
	//다른 표현으로는
	//int h = (int)ceil(log2(N));
	//SIZE = 1 << (h+1);
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[sz + i] = num;
	}
	construct();

	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) Update(b - 1 + sz, c);
		else cout << sum(b, c, 1, 1, sz) << "\n";
	}

	return 0;
}