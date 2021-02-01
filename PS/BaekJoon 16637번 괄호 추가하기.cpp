#include <bits/stdc++.h>
using namespace std;
#define INF INT_MIN
typedef long long int ll;

int N;
string s;
int ans = -INF;

void input() {
	int N; cin >> N; cin >> s;
}

void solution(int cnt, int value) {
	if (cnt >= N) {
		ans = max(ans, value);
		return;
	}
	if (cnt == 0) return solution(++cnt, s[0] - '0');
	else {

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}