#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


map<string, int> mp;
vector<string> aaa(6);
vector<int> bbb;
bool visited[11];


void make(int idx, int cnt, string noworder,string order) {
	if (idx == order.size()) return;
	if (cnt == 0) {
		sort(noworder.begin(), noworder.end());
		mp[noworder]++;
		return;
	}
	else {
		for (int i = idx; i < order.size(); i++) {
			if (!visited[i]) {
				visited[i] = 1;
				make(i, cnt - 1, noworder + order[i], order);
				visited[i] = 0;
			}
		}
	}
}

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	
	for (auto no : orders) {
		for (auto num : course) {
			memset(visited, 0, sizeof(visited));
			make(0, num, "", no);
		}
	}
	vector<pair<int, string>> vec[11];
	for (auto a : mp) {
		//cout << a.first << " " <<a.second << "\n";
		if (a.second < 2) continue;
		vec[a.first.size()].push_back({ a.second, a.first });
	}
	for (int i : course) {
		sort(vec[i].begin(), vec[i].end(), compare);
		int len = vec[i].empty() ? 0 :vec[i][0].first;
		for (auto now : vec[i]) {
			if (now.first == len) answer.push_back(now.second);
		}
	}
	sort(answer.begin(), answer.end());
	for (auto a : answer) {
		sort(a.begin(), a.end());
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution(aaa,bbb);
	return 0;
}