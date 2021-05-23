#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <pair<int, int>> vec;
int box[20];
int L, W, H, N, a, b, cnt = 0, flag = 0;
void solution(int l, int w, int h, int idx) {
	if (l == 0 || w == 0 || h == 0) return;
	for (int i = idx; i < vec.size(); i++) {
		if (vec[i].second != 0 && l >= vec[i].first && w >= vec[i].first && h >= vec[i].first) {
			vec[i].second--;
			cnt++;
			solution(l - vec[i].first, w, h, i);
			solution(vec[i].first, w - vec[i].first, h, i);
			solution(vec[i].first, vec[i].first, h - vec[i].first, i);
			return;
		}
	}
	flag = 1;
}
int main() {
	cin >> L >> W >> H >> N;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		box[a] += b;
	}
	for (int i = 19; i >= 0; i--) {
		if (box[i] != 0) {
			vec.push_back(make_pair(pow(2, i), box[i]));
		}
	}
	solution(L, W, H, 0);
	if (flag) cout << -1;
	else cout << cnt << endl;
	return 0;
}
//°øºÎ¿ë copy code