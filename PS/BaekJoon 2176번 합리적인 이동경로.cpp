#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M;
vector<pair<int,int>> edge[1000 + 1];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
}

void solution() {
	priority_queue<pair<int, int>> pq;
	while (!pq.empty()) {

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