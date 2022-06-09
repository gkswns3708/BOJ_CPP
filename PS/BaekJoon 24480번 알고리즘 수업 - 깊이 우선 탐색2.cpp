#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, M, R;
vector<int> adj[100001];
vector<int> dist;
int idx = 1;
void DFS(int pos) {
    dist[pos] = idx++;
    for (auto nxt : adj[pos]) if (dist[nxt] == 0) DFS(nxt);
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> R;
    dist.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int from, to; cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end(), greater<int>()); // 내림 차순 정렬
    DFS(R);
    for (int i = 1; i <= N; i++) cout << dist[i] << "\n";
    return 0;
}