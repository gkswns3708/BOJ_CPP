#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef struct Node	{
	int destination, maxjew; 
}Node;
int N, M, K;
vector<int> island;
vector<Node> edge[100+2];
bool visited[100 + 2][(1 << 15) + 1];
bool exist(int num) {
	for (auto a : island) {
		if (a == num) return true;
	}
	return false;
}
int BFS() {

	//시작, 끝, 현재까지의 보석 갯수, 보석 종류를 표현한 수
	queue<tuple<int, int, int, int>> que;
	vector<int> ans;
	int maxvalue = 0;
	for (auto a : edge[1]) {
		que.push({ 1,a.destination,0,1 });
		visited[a.destination][1] = true;
	}
	while (!que.empty()) {
		auto [from, to, nownum, nowjew] = que.front();
		if (to == 1) {
			if (exist(1))	maxvalue = max(maxvalue,nownum + 1);
			else maxvalue = max(maxvalue, nownum);
		}
		que.pop();
		for (auto a : edge[to]) {
			if (visited[a.destination][nowjew]) continue;
			if (a.maxjew >= nownum) {
				visited[a.destination][nowjew] = true;
				que.push({ to,a.destination,nownum,nowjew });
			}
			if (a.maxjew > nownum && exist(a.destination)&& !(nowjew & 1 << a.destination)) {
				visited[a.destination][nowjew | 1<<a.destination] = true;
				que.push({ to,a.destination,nownum + 1,nowjew | 1 << a.destination });
			}
		}
	}
	return maxvalue;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int temp; cin >> temp; island.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		int from, to, weight; cin >> from >> to >> weight;
		edge[from].push_back({ to,weight });
		edge[to].push_back({ from,weight });
	}
	cout << BFS() << "\n";
	return 0;
}
