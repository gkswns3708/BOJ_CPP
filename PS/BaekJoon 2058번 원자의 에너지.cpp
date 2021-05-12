#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

vector<int> edge[200 + 1][200 + 1];
vector<int> e;
int status[200 + 1];
bool energy[1000000 + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	e.resize(M);
	for (int i = 1; i <= N; i++) cin >> status[i];
	for (int i = 0; i < M; i++) cin >> e[i];
	

	return 0;
}