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
	//���� �ȿ� ���� �� + �ش� Ű�� ��� �湮���� �ʾ��� ��
	if (y >= 0 && y < N && x >= 0 && x < M && !visited[y][x][key]) {
		//������ �빮�� ����(��)�� ��
		if (arr[y][x] >= 'A' && arr[y][x] <= 'Z') {
			if (key & (1 << (arr[y][x] - 'A'))) {
				//cout << "---���� key �� : " << key << " ���Ϸ��� arr�� " << arr[y][x] << "\n";
				return true;
			}
			else return false;
		}
		//������ ���� ��
		else if (arr[y][x] == '#') return false;
		//������ (key, ���)
		else return true;
	}
	else return false;
}

int BFS() {
	//y,x,key bit ǥ��
	int dist = 0;
	//cout << start.first << " " << start.second << "\n";
	queue<tuple<int, int, int, int>> que;
	que.push({ start.first,start.second,0,0 });
	visited[start.first][start.second][0] = true;

	while (!que.empty()) {
		auto [y, x, nowdist, key] = que.front();
		//cout << "���� key�� ������� ��ġ " << y << " " << x << " " << nowdist  <<" " <<key <<"\n";
		if (arr[y][x] == '1') return nowdist;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			int nowkey = key;
			if (possible(nexty, nextx, nowkey)) {
				if (arr[nexty][nextx] >= 'a' && arr[nexty][nextx] <= 'z') {
					//cout <<"�������� ��ġ : " <<nexty <<"  "<<nextx << " dist :" << nowdist+1 <<"key���� ��ȭ : " << key << " -> ";
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