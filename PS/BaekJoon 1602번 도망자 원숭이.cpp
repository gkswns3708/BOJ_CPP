#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 987654321
using namespace std;

int N, M, Q;
vector<pii> dw_index;
int dist[500 + 1][500 + 1];
int dog_cost[500 + 1][500 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) {
		int weight; cin >> weight;
		dog_cost[i][i] = weight;
		dw_index.push_back({ weight,i });
	}
	//sort(dw_index.begin(), dw_index.end());
	
	for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) {
		dog_cost[i][j] = max(dog_cost[i][i], dog_cost[j][j]);
		if (i != j) dist[i][j] = INF; //dist를 초기화
		else dist[i][i] = dog_cost[i][i]; // 자기자신은 0 + 개
	}
	for (int i = 0; i < M; i++) {
		int st, ed, length; cin >> st >> ed >> length;
		dist[ed][st] = dist[st][ed] = length + max(dog_cost[st][st], dog_cost[ed][ed]);
	}

	auto Floyd_washall = [&]()-> void {
		for(const auto &dwcost : dw_index){
			auto [dwc, dwindex] = dwcost;
			for (int st = 1; st <= N; st++) {
				for (int ed = 1; ed <= N; ed++) {
					int Max_Dog_Cost = max(dwc, dog_cost[st][ed]);
					int nDist = (dist[st][dwindex] - dog_cost[st][dwindex] + dist[dwindex][ed] - dog_cost[dwindex][ed]) + Max_Dog_Cost;
					if (dist[st][ed] > nDist) {
						dist[st][ed] = nDist;
						dog_cost[st][ed] = Max_Dog_Cost;
					}
				}
			}
		}
	};

	Floyd_washall();
	for (int i = 0; i < Q; i++) {
		int st, ed; cin >> st >> ed;
		if (dist[st][ed] == INF) cout << "-1\n";
		else cout << dist[st][ed] << "\n";
	}
	return 0;
}