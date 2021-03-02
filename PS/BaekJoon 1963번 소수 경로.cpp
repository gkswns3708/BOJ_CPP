#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

vector<int> prime;
vector<string> sprime;

bool possible[10000+1][10000+1];

bool is_composite[10000+1];
bool visited[10000 + 1];

void sieve(int n) {
	for (int i = 0; i < n; ++i) is_composite[i] = false;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back(i);
			if(i >=1000)sprime.push_back(to_string(i));
		}
		for (int j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int BFS(int st, int ed) {
	queue<int> que;
	que.push(st);
	visited[st] = 1;
	int dist = 0;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			int now = que.front();
			if (now == ed) return dist;
			//cout << nownum << "-nownum\n";
			que.pop();
			for (auto nxt : prime) {
				if (visited[nxt]) continue;
				if (possible[now][nxt]) {
					//cout << nownum << " " << nxtnum << "\n";
					que.push(nxt);
					visited[now] = 1;
				}
			}
		}
		dist++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve(10000);
	for (string first : sprime) {
		for (string second : sprime) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) if (first[i] == second[i]) cnt++;
			if (cnt == 3) possible[stoi(first)][stoi(second)] = possible[stoi(second)][stoi(first)] = 1;
		}
	}
	int TC; cin >> TC;
	while (TC--) {
		memset(visited, 0, sizeof(visited));
		int a, b; cin >> a >> b;
		int now = BFS(a, b);
		if (now == -1) cout << "Impossible\n";
		else cout << now<<"\n";
	}
	return 0;
}