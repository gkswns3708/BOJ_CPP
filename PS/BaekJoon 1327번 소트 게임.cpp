#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N, K;
string ST;
map<string, bool> visited;

int BFS(string s) {
	string end = s;
	sort(end.begin(), end.end());
	queue<pair<string, int>> que;
	que.push(pair<string, int>(s, 0));
	visited[s] = true;

	while (!que.empty()) {
		string now = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (now == end) return cnt;
		for (int i = 0; i <= N - K; ++i) {
			string temp = now.substr(i, K);
			reverse(temp.begin(), temp.end());
			string next = now.substr(0, i);
			next += temp;
			next += now.substr(i + K);
			if (!visited.count(next)) {
				que.push({ next, cnt + 1 });
				visited[next] = true;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		char a;
		cin >> a;
		ST += a;
	}
	cout << BFS(ST) << '\n';
	return 0;
}