#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M;
char arr[55][55];
bool visited[55][55][(1<<6)+1];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
pair<int, int> start;

bool possible(int y, int x, int key) {
	//범위 안에 들어올 때 + 해당 키를 들고 방문하지 않았을 때
	if (y >= 0 && y < N && x >= 0 && x < M && !visited[y][x][key]) {
		//다음께 대문자 영어(문)일 때
		if (arr[y][x] >= 'A' && arr[y][x] <= 'Z') {
			if (key & (1 << (arr[y][x] - 'A'))) {
				//cout << "---현재 key 값 : " << key << " 비교하려는 arr값 " << arr[y][x] << "\n";
				return true;
			}
			else return false;
		}
		//다음께 벽일 때
		else if (arr[y][x] == '#') return false;
		//나머지 (key, 빈곳)
		else return true;
	}
	else return false;
}

int BFS() {
	//y,x,key bit 표현
	int dist = 0;
	//cout << start.first << " " << start.second << "\n";
	queue<tuple<int, int, int, int>> que;
	que.push({ start.first,start.second,0,0 });
	visited[start.first][start.second][0] = true;

	while (!que.empty()) {
		auto [y, x, nowdist, key] = que.front();
		//cout << "현재 key와 고려중인 위치 " << y << " " << x << " " << nowdist  <<" " <<key <<"\n";
		if (arr[y][x] == '1') return nowdist;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			int nowkey = key;
			if (possible(nexty, nextx, nowkey)) {
				if (arr[nexty][nextx] >= 'a' && arr[nexty][nextx] <= 'z') {
					//cout <<"검토중인 위치 : " <<nexty <<"  "<<nextx << " dist :" << nowdist+1 <<"key값의 변화 : " << key << " -> ";
					nowkey = key | (1 << (arr[nexty][nextx] - 'a'));
					//cout << key <<"\n";

				}
				visited[nexty][nextx][key] = true;
				que.push({ nexty,nextx,nowdist+1,nowkey });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = temp[j];
			if (temp[j] == '0') {
				start = { i,j };
				arr[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
		}
	}
	cout << BFS();
	return 0;
}