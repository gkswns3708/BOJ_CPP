#include <iostream>
#include <limits.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

int visited[26], arr[26], dist[26];
bool exist[26];
vector<int> edge[26];

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (getline(cin, s)) {
		stringstream in(s);
		char cur; int value; string next;
		in >> cur >> value >> next;
		arr[cur - 'A'] = value;
		visited[cur - 'A'] = next.length();
		exist[cur - 'A'] = true;
		for (char s : next) edge[s - 'A'].push_back(cur - 'A');
	}
}

ll solution() {
	queue<int> que;
	for (int i = 0; i < 26; i++) {
		if (!exist[i]) continue;
		if (!visited[i]) que.push(i), dist[i] = arr[i];
	}
	while (!que.empty()) {
		int now = que.front(); que.pop();
		for (auto next : edge[now]) {
			dist[next] = max(dist[next], dist[now] + arr[next]);
			visited[next]--;
			if (visited[next] == 0)que.push(next);
		}
	}
	int minvalue = 0;
	for (int i = 0; i < 26; i++) {
		if (!exist[i]) continue;
		minvalue = max(minvalue, dist[i]);
	}
	return minvalue;
}

int main() {
	input();
	cout << solution();
	return 0;
}