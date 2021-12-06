// 두 단계 최단 경로 3
#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
typedef pair<int, int> pii;
int dist[100'001];

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<pii> adj[100'001];
    vector<int> midpoint;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    int st, en, p;
    cin >> st >> en >> p;
    for (int i = 0; i < p; ++i) {
        int y;
        cin >> y;
        midpoint.push_back(y);
    }
    fill(dist + 1, dist + n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dist[st] = 0;
    PQ.push({ dist[st], st });
    while (!PQ.empty()) {
        auto [idx, cost] = PQ.top();
        PQ.pop();
        if (dist[idx] != cost) {
            continue;
        }
        for (auto [ncost, nidx] : adj[idx]) {
            if (dist[nidx] > cost + ncost) {
                dist[nidx] = cost + ncost;
                PQ.push({ dist[nidx], nidx });
            }
        }
    }
    cout << (dist[en] == INF ? -1 : dist[en]);
    return 0;
}