#include <bits/stdc++.h>
#define int long long int
using namespace std;
int psume[100000 + 10] = { 0, };
int psumo[100000 + 10] = { 0, };
int arr[100000 + 10] = { 0, };
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int n; cin >> n;
		memset(psume, 0, sizeof(psume));
		memset(psumo, 0, sizeof(psumo));
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) cin >> arr[i];
		int ans = n*arr[0] + n*arr[1];
		int sumo = arr[1],sume = arr[0];
		int cnt1 = 1, cnt2 = 1;
		int mine, mino;
		mine = arr[0], mino = arr[1];
		for (int i = 2; i < n; i++) {
			int ne, no;
			if (i % 2 == 0) sume += arr[i], mine = min(mine,arr[i]),cnt1++;
			else sumo += arr[i], mino = min(mino, arr[i]),cnt2++;
			ne = sume - mine + (n - cnt1 +1) * mine;
			no = sumo - mino + (n - cnt2+1) * mino;
			ans = min(ans, ne +  no);
		}
		cout << ans << "\n";
	}
	return 0;
}
