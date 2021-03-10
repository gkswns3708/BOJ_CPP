#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define INF 200000+100

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, H; cin >> N >> H;
	vector<int> evenH(H+2), oddH(H+2);
	vector<int> ans(H + 2);
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		if (i % 2 == 0) evenH[temp]++;
		else oddH[H-temp+1]++;
	}
	for (int i = H; i >= 1; i--) evenH[i] += evenH[i + 1], oddH[H - i + 1] += oddH[H - i];
	int mn = INF;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		ans[i] = evenH[i] + oddH[i];
		if (mn == ans[i]) { 
			cnt++;
		}
		else if (mn > ans[i]) {
			mn = ans[i];
			cnt = 1;
		}
	}

	cout << mn << " " << cnt;

	return 0;
}