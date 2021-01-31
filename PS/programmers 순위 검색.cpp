#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef long long int ll;
//노드의 수 n , 시작지점 s , a의 도착 지점 a, b의 도착 지점 b
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	int edge[210][210] = { 0, };
	for (int i = 0; i < 210; i++) {
		for (int j = 0; j < 210; j++) {
			edge[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) edge[i][i] = 0;
	for (auto now : fares) {
		int from, to, dist;
		from = now[0], to = now[1], dist = now[2];
		edge[from][to] = dist;
		edge[to][from] = dist;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (edge[j][k] > edge[j][i] + edge[i][k])
					edge[j][k] = edge[j][i] + edge[i][k];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (edge[s][i] == INF || edge[i][a] == INF || edge[i][b] == INF) continue;
		answer = min(answer, edge[s][i] + edge[i][a] + edge[i][b]);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	//input();
	//solution();
	return 0;
}