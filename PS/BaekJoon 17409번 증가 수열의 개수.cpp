#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

struct ST {
	int STN, STK;
	ST(int& n, int& k) {
		cin >> n >> k;
		STN = n, STK = k;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;
	ST st(N, K);
	return 0;
}