#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int arr[100 + 1][100 + 1];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int A, B, N, M;
typedef struct Robot {
	int y, x, dir;
}Robot;
vector<Robot> robot(100);

void Rotate_LR(int num, char command,int cnt) {
	int temp;
	if (command == 'L') temp = 1;
	else temp = 3;
	for (int i = 0; i < cnt; i++) {
		robot[num].dir = (robot[num].dir + temp) % 4;
	}
}


bool possible(int y, int x, int num) {
	if (y >= 1 && y <= B && x >= 1 && x <= A) {
		for (int i = 1; i <= N; i++) {
			if (i == num) continue;
			else if (robot[i].x == x && robot[i].y == y) {
				cout << "Robot " << num << " crashes into robot " << i;
				return true;
			}
		}
	}
	else {
		cout << "Robot " << num << " crashes into the wall";
		return true;
	}
	return false;
}

bool move(int num, int cnt) {
	for (int i = 0; i < cnt; i++) {
		int ny = robot[num].y + dy[robot[num].dir];
		int nx = robot[num].x + dx[robot[num].dir];
		if (possible(ny, nx, num)) return false;
		robot[num].y = ny;
		robot[num].x = nx;
 	}
	return true;
}

bool input() {
	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++) {
		char dir; int temp;
		cin >> robot[i].x >> robot[i].y >> dir;
		if      (dir == 'E') robot[i].dir = 0;
		else if (dir == 'N') robot[i].dir = 1;
		else if (dir == 'W') robot[i].dir = 2;
		else if (dir == 'S') robot[i].dir = 3;
	}
	for (int i = 0; i < M; i++) {
		int num,cnt; char command;
		cin >> num >> command >> cnt;
		if (command == 'F') {
			if (move(num, cnt)) continue;
			else return false;
		}
		else Rotate_LR(num, command, cnt);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin.out;
	if (input()) cout << "OK";
	return 0;
}

