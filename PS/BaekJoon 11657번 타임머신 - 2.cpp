#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int dist[500 + 1];
vector<pii> edge[500 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, dist; cin >> from >> to >> dist;
		edge[from].push_back({ to,dist });
	}
	for (int i = 2; i <= N; i++) dist[i] = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (const auto& now : edge[j]) {
				auto [nxt, length] = now;
				if (dist[nxt] > dist[j] + length && dist[j] != INF) {
					dist[nxt] = dist[j] + length;
					//�̷��� �Ǻ��ص� �Ǵ����� dist�� 1�����κ����� �Ÿ��̱� ����
					//dist�� �ǹ̰� �ٸ� ��� 1���� �������� �Ǻ��ؾ���.
					if (i == N) {
						cout << "-1\n";
						exit(0);
					}
				}
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';
	}
	return 0;
}