#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 1000000007
using namespace std;

int N, M,sz = 1;
pii arr[300000 + 1];


int Min(int L, int R, int nodeNum, int posL, int posR) {
	if (R < posL || L > posR) return INF;
	if (L <= posL && R >= posR) return arr[nodeNum].second;
	int mid = (posL + posR) / 2;
	return min(Min(L, R, nodeNum * 2, posL, mid), Min(L, R, nodeNum * 2 + 1, mid + 1, posR));
}

int Max(int L, int R,int nodeNum, int posL, int posR) {
	if (R < posL || L > posR) return -INF;
	if (L <= posL && R >= posR) return arr[nodeNum].first;
	int mid = (posL + posR) / 2;
	return max(Max(L, R, nodeNum * 2, posL, mid), Max(L, R, nodeNum * 2 + 1, mid + 1, posR));

}

void construct() {
	for (int i = sz - 1; i >=0 ; i--) {
		arr[i].first  = max(arr[i * 2].first, arr[i * 2 + 1].first);
		arr[i].second = min(arr[i * 2].second, arr[i * 2 + 1].second);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	while (sz < N) sz <<= 1;

	pii tmppii = { -INF,INF };
	fill(arr, arr + 300000, tmppii);
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[sz + i].first = temp;
		arr[sz + i].second = temp;
	}
	construct();

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << Min(a,b,1,1,sz) << " " <<Max(a,b,1,1,sz) << "\n";
	}

	return 0;
}