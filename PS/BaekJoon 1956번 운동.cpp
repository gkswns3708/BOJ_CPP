#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define INF 987654321
#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }


int ans[400 + 1][400 + 1];
int V, E;
int answer = INF;
void input() {
	cin >> V >> E;
	for (int i = 0; i < 401; i++)
		for (int j = 0; j < 401; j++)
			ans[i][j] = INF;
	for (int i = 0; i < E; i++) {
		int from, to, dist; cin >> from >> to >> dist;
		ans[from][to] = dist;
	}		
}

void solution() {
	for (int i = 1; i <= V; i++) 
		for (int j = 1; j <= V; j++) 
			for (int k = 1; k <= V; k++) 
				ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
	for (int i = 1; i < V; i++) 
		for (int j = i + 1; j <= V; j++) 
			answer = min(answer, ans[i][j] + ans[j][i]);
	
	if (answer >= INF) cout << -1;
	else cout << answer;
}



int main() {
	fastio;
	input();
	solution();
}