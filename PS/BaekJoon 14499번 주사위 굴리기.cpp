#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int cube[10];
int arr[25][25];
int N, M,K;

int dx[] = {0 ,1,-1,0,0 };
int dy[] = {0 ,0, 0,-1,1 };

pair<int, int> nowpos = {0,0};
bool possible(int y, int x) {
	if (y < N && y >= 0 && x < N && x >= 0) return true;
	else return false;
}
void rotate_R(int y, int x) {
	//바닥과 swap을 한뒤
	if (arr[y][x] == 0) {
		arr[y][x] = cube[6];
		cube[6] = 0;
	}
	else {
		cube[6] = arr[y][x];
		arr[y][x] = 0;
	}
	int temp = cube[6];
	cube[6] = cube[3];
	cube[3] = cube[1];
	cube[1] = cube[4];
	cube[4] = temp;
}
void rotate_L(int y, int x) {
	if (arr[y][x] == 0) {
		arr[y][x] = cube[6];
		cube[6] = 0;
	}
	else {
		cube[6] = arr[y][x];
		arr[y][x] = 0;
	}
	int temp = cube[6];
	cube[6] = cube[4];
	cube[4] = cube[1];
	cube[1] = cube[3];
	cube[3] = temp;
}
void rotate_U(int y, int x) {
	if (arr[y][x] == 0) {
		arr[y][x] = cube[6];
		cube[6] = 0;
	}
	else {
		cube[6] = arr[y][x];
		arr[y][x] = 0;
	}
	int temp = cube[6];
	cube[6] = cube[5];
	cube[5] = cube[1];
	cube[1] = cube[2];
	cube[2] = temp;
}
void rotate_D(int y, int x) {
	if (arr[y][x] == 0) {
		arr[y][x] = cube[6];
		cube[6] = 0;
	}
	else {
		cube[6] = arr[y][x];
		arr[y][x] = 0;
	}
	int temp = cube[6];
	cube[6] = cube[2];
	cube[2] = cube[1];
	cube[1] = cube[5];
	cube[5] = temp;
}

int move(int dir) {
	int num = dir;
	if (possible(nowpos.first + dy[dir], nowpos.second + dx[dir])) {
		if (dir == 1) {
			rotate_R(nowpos.first + dy[dir], nowpos.second + dx[dir]);
			cout << "case0 " << "\n";
			nowpos.first += dy[dir];
			nowpos.second += dx[dir];
		}
		else if (dir == 2) {
			rotate_L(nowpos.first + dy[dir], nowpos.second + dx[dir]);
			cout << "case1" << "\n";
			nowpos.first += dy[dir];
			nowpos.second += dx[dir];
		}
		else if (dir == 3) {
			rotate_U(nowpos.first + dy[dir], nowpos.second + dx[dir]);
			cout << "case2" << "\n";
			nowpos.first += dy[dir];
			nowpos.second += dx[dir];
		}
		else if (dir == 4) {
			rotate_D(nowpos.first + dy[dir], nowpos.second + dx[dir]);
			cout << "case3" << "\n";
			nowpos.first += dy[dir];
			nowpos.second += dx[dir];
		}
	}
	return cube[1];
}


int main() {
	fastio;
	cin >> N >> M;
	int cubex, cubey; cin >> cubex>>cubey>>K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int temp; cin >> temp;
		cout << move(temp)<<"\n";
	}
	return 0;
}
