#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N;
int ans;
vector<pair<int, int>> vec(1000000);

void input() {
	cin >> N;
	int x,y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vec[i] = { x,y };
	}
}

void solution() {

	int first, last;
	first = vec[0].first;
	last = vec[0].second;
	//첫 거리
	ans += last - first;
	for (int i = 1; i < N; i++) {
		//겹치는 경우
		if (last >= vec[i].first) {
			if (vec[i].second <= last) continue;
			ans += vec[i].second - last;
			last = vec[i].second;
		}
		//겹치지 않는 경우
		else {
			first = vec[i].first;
			last = vec[i].second;
			ans += last - first;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	input();
	solution();
	
	cout << ans;

	return 0;
}