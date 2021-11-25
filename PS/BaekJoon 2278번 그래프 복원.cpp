#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, M;
int min_dist[100 + 2][100 + 2];
int directed_dist[100 + 2][100 + 2];
bool visited[100 + 2][100 + 2];
tiii st_point;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N;i++) {
        for (int j = 1; j <= i;j++) {
            cin >> min_dist[i][j];
            min_dist[j][i] = min_dist[i][j];
            auto [st, ed, value] = st_point;
            if (value > min_dist[i][j]) st_point = { st,ed,min_dist[i][j] };
        }
    }
    queue<tiii> que;
    que.push(st_point);
    while(!que.empty()) {
        auto [st, ed, value] = que.front();
        
        for (int i = 1; i <= N;i++) {
            min_dist[st][ed] 
        }
    }
    return 0;
}