#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1025+10][1024+10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) {
			int temp; cin >> temp;
			arr[i][j] = arr[i][j-1] + temp;
		}
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	while (M--) {
		int x1, y1, x2, y2, sum = 0;; cin >>y1 >> x1 >> y2 >> x2;
		for (int i = y1; i <= y2; i++) 	sum += arr[i][x2] - arr[i][x1-1];
		cout << sum << "\n";
	}

	return 0;
}