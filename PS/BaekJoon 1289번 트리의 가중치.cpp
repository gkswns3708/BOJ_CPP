#include <bits/stdc++.h>
#define X first
#define Y second
#define MOD 1000000007
using namespace std;
typedef long long int ll;


vector<pair<int,int>> node[100000 + 1];
bool visited[100000 + 1];
ll dist[100000 + 1];
ll cost = 0;

ll mod(ll a) {
	if (a % MOD < 0)
		return a % MOD + MOD;
	return a % MOD;	
}

ll square(ll a) {
	return mod(a * a);
}


void input() {
	int N; cin >> N;
	for (int i = 0,A,B,W; i < N - 1; i++) {
		cin >> A >> B >> W;
		node[A].push_back({ B,W });
		node[B].push_back({ A,W });
	}
}


void DFS(int now) {
	visited[now] = true;
	ll subtree_sum = 0;
	ll add_cost = 0;
	for (auto nxt : node[now]) {
		if (visited[nxt.X]) continue;
		visited[nxt.X] = true;
		DFS(nxt.X);
		ll elem = mod((dist[nxt.X] + 1) * nxt.Y);
		subtree_sum = mod(subtree_sum + elem);
		add_cost = mod(add_cost - square(elem));
	}
	add_cost = mod(add_cost + square(subtree_sum));
	if (add_cost % 2 == 0)
		cost = mod(cost + add_cost / 2);
	else
		cost = mod(cost + (add_cost + MOD) / 2);
	dist[now] = mod(subtree_sum);
	cost = mod(cost + dist[now]);
}

void solution() {
	//트리의 특성상 아무 한 점을 잡아도 root가 될 수 있음.
	DFS(1);
	cout << cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();

	return 0;
}