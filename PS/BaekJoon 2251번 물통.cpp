#include <bits/stdc++.h>
using namespace std;

bool visited[200 + 1][200 + 1][200 + 1];
int A, B, C;

int main() {
	cin >> A >> B >> C;
	queue<tuple<int, int, int>> que;
	vector<int> ans;
	que.push({ 0,0,C });
	while (!que.empty()) {
		auto [a, b, c] = que.front();que.pop();
		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;
		if (a == 0) ans.push_back(c);
		if (a + b > B)	que.push({ a + b - B,B,c });
		else que.push({ 0,a + b,c });
		if (a + c > C)	que.push({ a + c - C , b, C });
		else que.push({ 0,b,a + c });
		if (b + a > A)	que.push({ A,b + a - A,c });
		else que.push({ b + a,0,c });
		if (b + c > C)	que.push({ a,b + c - C,C });
		else que.push({ a,0,b + c });
		if (c + a > A)	que.push({ A,b,c + a - A });
		else que.push({ c + a,b,0 });		
	}
	sort(ans.begin(), ans.end());
	for (auto a : ans)cout << a << " ";
	return 0;
}