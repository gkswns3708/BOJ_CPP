#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int N;
vector<int> Box;
bool visited[500000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N; Box.resize(N);
	for (int i = 0; i < N; i++) cin >> Box[i];
	sort(Box.begin(), Box.end());
	int cursor = 0, ans = 0, cursor2 = N / 2;
	while (cursor < N / 2 && cursor2 < N) {
		if (Box[cursor] * 2 <= Box[cursor2]) {
			cursor++;
			ans++;
			cursor2++;
		}
		else cursor2++;
	}
	cout << N - ans;
	return 0;
}