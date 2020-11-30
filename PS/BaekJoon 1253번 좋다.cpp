#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;

int arr[2001];
bool visited[2001];
int N;
int cnt;

bool check(int mid, int now,int idx1,int idx2) {
	if (mid - 2 >= 0 && arr[mid] == now && mid != idx1 && mid!=idx2) return true;
	if (mid - 1 >= 0 && arr[mid] == now && mid != idx1 && mid != idx2) return true;
	if (mid + 1 < N && arr[mid] == now && mid != idx1 && mid != idx2) return true;
	if (mid + 2 < N && arr[mid] == now && mid != idx1 && mid != idx2) return true;
	return false;
}

void ans(int now,int idx1,int idx2) {
	int l = 0,r = N - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] == now && check(mid, now,idx1,idx2)) {
			visited[mid] = true;
			return;
		}
		if (arr[mid] < now) l = mid + 1;
		else r = mid - 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			int now = arr[i] + arr[j];
			ans(now,i,j);
		}
	}
	for (auto a : visited)
		if (a) 	cnt++;
	cout << cnt;
	return 0;
}