#include <bits/stdc++.h>
#define int long long int
using namespace std;

int arr[10 + 1][10 + 1];
int dy[] = { 1,0 };
int dx[] = { 0,1 };
int score = 0;

struct Block {
	int t,  y,  x;
};

Block block[2];
void printarr() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool possiblegreen(int t, int y, int x) {
	if (y >= 10 || x >= 10) return false;
	if (arr[y][x] != 1) return 1;
	else return 0;
}

bool possibleblue(int t, int y, int x) { 
	if(t != 3)
	if (y >= 10 || x >= 10) return false;
	if (arr[y][x] != 1) return 1;
	else return 0;
}

void movetogreen() {
	while (possiblegreen(block[0].t, block[0].y + dy[0], block[0].x + dx[0])) {
		block[0].y += dy[0];
		block[0].x += dx[0];
		cout << block[0].y << " " << block[0].x << "- block의 위치\n";
	}
	if (block[0].t == 1) arr[block[0].y][block[0].x] = 1;
	else if (block[0].t == 2) arr[block[0].y][block[0].x] = 1, arr[block[0].y][block[0].x - 1] = 1;
	else arr[block[0].y][block[0].x] = arr[block[0].y - 1][block[0].x] = 1;
	printarr();
}

void movetoblue() {
	while (possibleblue(block[1].t, block[1].y + dy[1], block[1].x + dx[1])) {
		block[1].y += dy[1];
		block[1].x += dx[1];
		cout << block[1].y << " " << block[1].x << "- block의 위치\n";
	}
	if (block[1].t == 1) arr[block[1].y][block[1].x] = 1;
	else if (block[1].t == 2) arr[block[1].y][block[1].x] = 1, arr[block[1].y][block[1].x - 1] = 1;
	else arr[block[1].y][block[1].x] = arr[block[1].y -1][block[1].x] = 1;
	printarr();
}

void movegreen(int Y) {
	for (int y = Y; y >= 5; y--) for (int x = 0; x < 4; x++) arr[y][x] = arr[y-1][x];
}

void checkscroeblue() {
	for (int x = 6; x <= 9; x++) {
		bool flag = true;
		for (int y = 0; y < 4; y++) if (arr[y][x] == 0) flag = false;
		if (flag) movegreen(x),score++;
	}
}

void moveblue(int X) {
	for (int x = X; x >= 5; x--) for (int y = 0; y < 4; y++) arr[y][x] = arr[y][x-1];
}

void checkscroegreen() {
	for (int y = 6; y <= 9; y++) {
		bool flag = true;
		for (int x = 0; x < 4; x++) if (arr[y][x] == 0) flag = false;
		if (flag) moveblue(y), score++;
	}
}

void checkligthblue() {
	while (1) {
		bool flag = 0;
		for (int X = 4; X <= 5; X++) for (int Y = 0; Y < 4; Y++) if (arr[Y][X] == 1) flag = true;
		if (flag) moveblue(9);
		if (!flag) break;
	}
}

void checklightgreen() {
	while (1) {
		bool flag = 0;
		for (int Y = 4; Y <= 5; Y++) for (int X = 0; X < 4; X++) if (arr[Y][X] == 1) flag = true;
		if (flag) movegreen(9);
		if (!flag) break;
	}
}

void solution(int t, int y, int x) {
	block[0].t = t, block[0].y = y, block[0].x = x;
	block[1].t = t, block[1].y = y, block[1].x = x;
	movetoblue();
	movetogreen();
	checkscroeblue();
	checkscroegreen();
	checkligthblue();
	checklightgreen();
}


void printans() {
	printarr();
	cout << score << "\n";
	int ans = 0;
	for (int x = 6; x <= 9; x++) for (int y = 0; y < 4; y++) ans += arr[y][x];
	for (int y = 6; y <= 9; y++) for (int x = 0; x < 4; x++) ans += arr[y][x];
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int t, y, x; cin >> t >> y >> x;
		if (t == 2) x++;
		solution(t, y, x);
	}
	printans();
	return 0;
}