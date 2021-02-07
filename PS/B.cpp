#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define INF 987654321

int main() {
	fastio;
	int N;cin >> N;
	vector<int> vec(N + 10, -INF);
	int st = 1, end = N;
	vec[st] = INF;
	vec[end] = INF;
	int mid = (st + end) / 2;
	cout << "? " << mid<<"\n";
	cout.flush();
	cin >> vec[mid];
	//mid를 한번 받고 시작.
	while (st+2 < end) {
		int now;
		if (end - mid < mid - st) now = (mid + st) / 2;
		else now = (mid + end) / 2;
		cout << "? " << now<<"\n";
		cout.flush();
		cin >> vec[now];
		if (vec[now] < vec[mid]) {
			if (mid - st > end - mid) {
				end = mid;
				mid = now;
			}
			else {
				st = mid;
				mid = now;
			}
		}
		else {
			if (mid - st > end - mid) {
				st = now;
			}
			else {
				end = now;
			}
		}
	}
	cout << "! " << (st + end) / 2 << endl;
}