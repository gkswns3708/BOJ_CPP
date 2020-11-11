#include <bits/stdc++.h>
#pragma warning(disable:4996)

using namespace std;

int N, cnt;;
int arr[25 + 1][25 + 1];
int visited[25 + 1][25 + 1];

int a[5] = { 1,0,-1,0 };
int b[5] = { 0,-1,0,1 };

void DFS(int y, int x) {
	visited[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		if (visited[y + b[i]][x + a[i]] == 1 || arr[y + b[i]][x + a[i]] == 0) {
			continue;
		}
		else {
			DFS(y + b[i], x + a[i]);
		}
	}
}

int main() {
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && arr[i][j] == 1) {
				cnt = 0;
				DFS(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size()<<"\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
		printf("%d\n", v[i]);
	}

	return 0;
}