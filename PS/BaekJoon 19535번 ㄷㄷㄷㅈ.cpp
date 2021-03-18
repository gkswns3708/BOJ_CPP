#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> edge(N + 1);

	for (int i = 0; i < N - 1; ++i) {
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);	
	}

	int D = 0, G = 0, cnt = 1;
	for (auto now : edge) {
		int size = now.size();
		G += size * (size - 1) * (size - 2) / 6;
		for (auto nnow : now) {
			if (cnt > nnow) continue;
			else D += (size - 1) * (edge[nnow].size() - 1);
		}
		cnt++;
	}
	if (D > 3 * G) cout << "D";
	else if (D < 3 * G) cout << "G";
	else cout << "DUDUDUNGA";
	
	return 0;
}