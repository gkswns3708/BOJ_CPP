#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define INF LLONG_MAX/3
using namespace std;

int N, M, X, Z, P, ans = INF;
vector<int> order;
vector<pii> edge[100000 + 1];

void cal_dijkstra(int st, vector<int>& dist) {
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,st });
    while (!pq.empty()) {
        auto [now_dist, pos] = pq.top();
        pq.pop();
        if (dist[pos] != INF) continue;
        for (auto [nxt_dist, nxt_pos] : edge[pos]) {
            if (dist[nxt_pos] > dist[pos] + nxt_dist) {
                dist[nxt_pos] = dist[pos] + nxt_dist;
                pq.push({ dist[pos] + nxt_dist, nxt_pos });
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({ w,v });
        edge[v].push_back({ w,u });
    }
    cin >> X >> Z >> P;
    order.resize(P);
    vector<vector<int>> dist(P + 1, vector<int>(N + 1, INF));
    for (int i = 0; i < P; i++) cin >> order[i];
    for (int i = 0; i < P; i++) cal_dijkstra(order[i], dist[i]);
    vector<bool> permute(P, false);
    permute[P - 1] = permute[P - 2] = permute[P - 3] = true;
    do {
        vector<pii> mid;
        for (int i = 0; i < P; i++) if (permute[i] == true) mid.push_back({ order[i] ,i });
        if (dist[mid[0].second][X] != INF && // a -> st
            dist[mid[1].second][mid[0].first] != INF && // b -> a
            dist[mid[2].second][mid[1].first] != INF && // c -> b
            dist[mid[2].second][Z] != INF) {// c -> ed
            /*cout << X << "->" << mid[0].first << "->" << mid[1].first << "->" << mid[2].first << "->" << Z << "\n";
            cout << dist[mid[0].second][X] + dist[mid[1].second][mid[0].first] + dist[mid[2].second][mid[1].first] + dist[mid[2].second][Z] << "\n";*/
            ans = min(ans, dist[mid[0].second][X] + dist[mid[1].second][mid[0].first] + dist[mid[2].second][mid[1].first] + dist[mid[2].second][Z]);
        }
    } while (next_permutation(permute.begin(), permute.end()));
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}