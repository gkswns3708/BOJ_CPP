#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Taxi {
	int x, y, idx;
};
struct Pass {
	int x, y, goalx, goaly, idx, use;
};
Taxi taxi;
Pass pass[450];
bool visit[25][25];
int N, M, fuel;
int arr[25][25];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool possible(int y, int x) {
	if (y >= 1 && y <= N && x >= 1 && x <= N && !visit[y][x]) return true;
	else return false;
}

void makewall() {
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (arr[i][j] == 1) visit[i][j] = true;
		else visit[i][j] = false;
	}
}
void DestToPass() {
	makewall();
	queue<pair<int, int>> que;
	que.push({ taxi.y,taxi.x });
	int dist = -1;
	bool check = false;
	vector<pair<int, int>> ans;
	while (!que.empty()) {
		if (check) break;
		int size = que.size();
		while (size--) {
			int y = que.front().first;
			int x = que.front().second;
			if (arr[y][x] != 0 && pass[arr[y][x]].use == false) {
				visit[y][x] = true;
				check = true;
				ans.push_back({ y,x });
			}
			que.pop();
			for (int i = 0; i < 4; i++) {
				int nowy = y + dy[i];
				int nowx = x + dx[i];
				if (possible(nowy, nowx)) {
					visit[nowy][nowx] = true;
					que.push({ nowy,nowx });
				}
			}
		}
		dist++;
	}
	if (dist > fuel) fuel = -1;
	if (!ans.empty())
	{
		sort(ans.begin(), ans.end());
		taxi.y = ans[0].first;
		taxi.x = ans[0].second;
		taxi.idx = arr[ans[0].first][ans[0].second];
		pass[taxi.idx].use = true;
	}
	if (dist > fuel || ans.empty()) fuel = -1;
	else fuel -= dist;
}
void DestToDest() {
	makewall();
	queue<pair<int, int>> que;
	que.push({ taxi.y,taxi.x });
	int idx = taxi.idx;
	int goaly = pass[idx].goaly;
	int goalx = pass[idx].goalx;
	int dist = -1;
	bool check = false;
	vector<pair<int, int>> ans;
	while (!que.empty()) {
		if (check) break;
		int size = que.size();
		while (size--) {
			int y = que.front().first;
			int x = que.front().second;
			if (y == goaly && x == goalx) {
				visit[y][x] = true;
				check = true;
				ans.push_back({ y,x });
			}
			que.pop();
			for (int i = 0; i < 4; i++) {
				int nowy = y + dy[i];
				int nowx = x + dx[i];
				if (possible(nowy, nowx)) {
					visit[nowy][nowx] = true;
					que.push({ nowy,nowx });
				}
			}
		}
		dist++;
	}
	if (!ans.empty())
	{
		sort(ans.begin(), ans.end());
		taxi.y = ans[0].first;
		taxi.x = ans[0].second;
	}
	if (dist > fuel || ans.empty()) fuel = -1;
	else fuel += dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) cin >> arr[i][j];
	cin >> taxi.y >> taxi.x;
	for (int i = 1; i <= M; i++) {
		cin >> pass[i + 1].y >> pass[i + 1].x >> pass[i + 1].goaly >> pass[i + 1].goalx;
		arr[pass[i + 1].y][pass[i + 1].x] = i + 1;
		pass[i + 1].idx = i + 1;
		pass[i + 1].use = false;
	}
	for (int i = 0; i < M; i++) {
		DestToPass();
		if (fuel == -1)break;
		//cout << "택시위치 : " << taxi.y << " " << taxi.x << "남은 연료량 : " << fuel << "\n";
		DestToDest();
		if (fuel == -1)break;
		//cout << "택시위치 : " << taxi.y << " " << taxi.x << "남은 연료량 : " << fuel << "\n";
	}
	cout << fuel;
	return 0;
}