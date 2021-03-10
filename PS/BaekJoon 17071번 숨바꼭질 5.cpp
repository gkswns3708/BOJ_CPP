#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
int N, K;
bool visited[500000 + 1][2];
bool possible(int pos, bool flag) {
	//홀수가 flag = 1
	if (pos <= 500000 && pos >= 0 && !visited[pos][flag]) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	
	
	queue <pair<int, int>> que;
	//위치,시간
	que.push({ N,0 });
	visited[N][0] = 1;
	int ans = INF;
	if (N == K) {
		cout << 0;
		return 0;
	}
	else {
		int dist = 0;
		while (!que.empty()) {
			dist++;
			auto [npos, ntime] = que.front();
			bool flag = (ntime + 1) % 2;
			if (npos == K + (ntime + 1) * ntime / 2) {
				ans = min(ans,ntime);
				break;
			}
			que.pop();
			if (possible(npos + 1, flag)) {
				que.push({ npos + 1,ntime+1});
				visited[npos + 1][flag] = true;
			}
			if (possible(npos - 1, flag)) {
				que.push({ npos - 1,ntime + 1 });
				visited[npos - 1][flag] = true;
			}
			if (possible(npos * 2, flag)) {
				que.push({ npos *2 ,ntime + 1 });
				visited[npos * 2][flag] = true;
			}
		}
	}

	cout << ans;

	return 0;
}