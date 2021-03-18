#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#define int long long int
using namespace std;

int N,length,M;
vector<tuple<int, int, int, int>> vec;
int height[5000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int a, b;
	cin >> a >> b;
	vec.resize((N - 2) / 2);
	for (int i = 0; i < (N-2)/2; i++) {
		int c, d, e, f; cin >> c >> d >> e >> f;
		vec[i] = { c,d,e,f };
	}
	cin >> length >> a;
	cin >> M;
	int mnlen = INF;
	while (M--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		for (auto now : vec) {
			auto [nx, ny, nx2, ny2] = now;
			if (x1 == nx) {

			}
		}
	}
	return 0;
}