#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, M, R;
vector<int> adj[100001];
vector<int> dist;
int idx = 1;
void BFS(int pos) {
    queue<int> que;
    que.push(pos);
    dist[pos] = idx++;
    while (!que.empty()) {
        auto now = que.front();
        que.pop();
        for (auto nxt : adj[now]) {
            if (!dist[nxt]) {
                que.push(nxt);
                dist[nxt] = idx++;
            }
        }
    }
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
    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end(), greater<int>()); // 오름 차순 정렬
    BFS(R);
    for (int i = 1; i <= N; i++) cout << dist[i] << "\n";
    return 0;
}