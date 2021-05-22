#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

char arr[2200][2200];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	function <void(int, int, int)> solution = [&](int y, int x, int size) -> void {
		if (size == 3) {
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1)continue;
					else arr[i + y][j + x] = '*';
				}
			}
		}
					
		else {
			size /= 3;
			for (int i = 0; i < 3; i++) 
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) continue;
					else solution(y + size * i, x + size * j, size);
				}
		}
	};
	memset(arr, ' ', sizeof arr);
	solution(0,0,N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	} 

	return 0;
}