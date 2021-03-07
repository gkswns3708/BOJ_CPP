#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void Greedy(string& s, int N, int K) {
	deque<char> dq;
	for (int i = 0; i < N; i++) {
		while (!dq.empty() && K != 0 && dq.back() < s[i]) {
			dq.pop_back();
			K--;
			for (auto now : dq) cout << now << " ";
			cout << "-pop_back()\n";
		}
		dq.push_back(s[i]);
		for (auto now : dq) cout << now << " ";
		cout << "\n";
	}

	while (K--)	dq.pop_back();

	for (auto now : dq) cout << now;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;

	string s; cin >> s;
	Greedy(s, N, K);
	return 0;
}