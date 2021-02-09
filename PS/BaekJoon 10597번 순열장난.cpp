#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s;
int N;
vector<int> vec;
bool visited[50 + 1];
int len;
void input() {
	cin >> s;
	len = s.length();
	if (len <= 9) N = len;
	else N = ((len - 9) / 2) + 9;
	visited[0] = true;
}

void solution(int pos) {
	if (pos == len) 	{
		for (auto a : vec)	cout << a << " "; 
		exit(0);
	}
	string temp;
	for (int j = 0; j < len && j < 2; j++) {
		temp += s[pos + j];
		int now = stoi(temp);
		if (!visited[now] && now <= N) {
			visited[now] = true;
			vec.push_back(now);
			solution(pos + j+1);
			vec.pop_back();
			visited[now] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution(0);
	return 0;
}