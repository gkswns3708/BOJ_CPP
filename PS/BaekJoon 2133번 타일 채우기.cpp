#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[35];
ll count(int cnt) {
	if (arr[cnt] != 0) return arr[cnt];
	
	return arr[cnt] = arr[cnt - 2] * 3 + arr[cnt - 6] * 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	arr[0] = 1;
	arr[2] = 3;	
	int N; cin >> N;
	for (int i = 4; i <= N; i+=2) {
		arr[i] = arr[i - 2] * 3;
		for (int j = 4; j <= i; j+=2) {
			arr[i] += arr[i - j] * 2;
		}
	}
	cout << arr[N];
	return 0;
}