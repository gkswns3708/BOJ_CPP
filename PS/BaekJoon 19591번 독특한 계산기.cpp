#include <bits/stdc++.h>
using namespace std;

int n, m, k, die, cnt;
bool r;
deque<int> dq;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) dq.emplace_back(i);
	while (!dq.empty()) {
		cnt = k - 1;
		if (!r) {
			while (cnt--) {
				dq.emplace_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else {
			while (cnt--) {
				dq.emplace_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		if (m == ++die) r = 1 - r, die = 0;
	}
}