#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef struct Node	{
	int dest, weight; 
}Node;
int N, M, K;
vector<pair<int,int>> island;
vector<Node> edge[100+2];
bool visited[100 + 2][(1 << 15) + 1];
bool exist(int num) {
	for (auto a : island) if (a.second == 1) return true;
	else return false;
}
int findjew(int nowislandnum) {
	for (auto a : island)if (a.second == nowislandnum) return a.first;
	else return 0;
}
int BFS() {
	//시작, 끝, 현재까지의 보석 갯수, 보석 종류를 표현한 수
	queue<tuple<int, int, int, int>> que;
	int ans = 0;
	que.push({ 0,1,0,1 });
	visited[1][1] = true;
	while (!que.empty()) {
		auto [from, to, num, kind] = que.front();
		cout << from << " " << to << " " << num << " ";
		for (int i = 1; i < 15; i++) if (kind & 1 << i) cout << i << " ";
		cout << "\n";
		que.pop();
		if (to == 1) {
			if (exist(1)) ans = max(ans, num + 1);
			else  ans = max(ans, num);
		}
		for (auto a : edge[to]) {
			if (a.weight < num ) continue;
			if (a.weight >= num && !visited[a.dest][kind]) {
				que.push({ to,a.dest,num,kind });
				visited[a.dest][kind] = true;
			}
			int nowkind = kind | 1 << findjew(a.dest);
			if (a.weight > num && findjew(a.dest)!=0 && !visited[a.dest][nowkind]) {
				que.push({ to,a.dest,num+1,nowkind });
				visited[a.dest][nowkind] = true;
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		int temp; cin >> temp; island.push_back({i,temp});
	}
	for (int i = 0; i < M; i++) {
		int from, to, weight; cin >> from >> to >> weight;
		edge[from].push_back({ to,weight });
		edge[to].push_back({ from,weight });
	}
	cout << BFS() << "\n";
	return 0;
}
