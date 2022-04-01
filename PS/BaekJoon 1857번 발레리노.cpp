#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, M;
int sy, sx;
int ey, ex;
int arr[30 + 1][30 + 1];
int cnt[30 + 1][30 + 1];
int dist[30 + 1][30 + 1];
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool visited[30 + 1][30 + 1];
vector<pii> vec[30 + 1][30 + 1];

bool possible(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < M && !visited[y][x]) return true;
    else return false;
}

void cal_dist(int y, int x, int nowy, int nowx) {
    visited[nowy][nowx] = 1;
    if (arr[nowy][nowx] == 2) return;
    if (arr[nowy][nowx] != 1 && !(y == nowy && x == nowx)) {
        vec[y][x].push_back({ nowy, nowx });
        return;
    }
    for (int i = 0; i < 8; i++) {
        int ny = nowy + dy[i], nx = nowx + dx[i];
        if (possible(ny, nx)) cal_dist(y, x, ny, nx);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 3) sy = i, sx = j;
            if (arr[i][j] == 4) ey = i, ex = j;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] != 2) {
                memset(visited, 0, sizeof(visited));
                cal_dist(i, j, i, j);
            }
        }
    }

    queue<pii> que;
    que.push({ sy, sx });
    dist[sy][sx] = 1;
    cnt[sy][sx] = 1;
    while (!que.empty()) {
        auto [y, x] = que.front();
        que.pop();
        for (auto now : vec[y][x]) {
            auto [ny, nx] = now;
            if (dist[ny][nx] == 0) { // 아직 방문 x
                dist[ny][nx] = dist[y][x] + 1;
                cnt[ny][nx] = cnt[y][x];
                que.push({ ny, nx });
            }
            else if (dist[ny][nx] == dist[y][x] + 1) cnt[ny][nx] += cnt[y][x];
        }
    }
    if (dist[ey][ex] == 0)cout << "-1";
    else cout << dist[ey][ex] - 2 << "\n" << cnt[ey][ex];

    return 0;
}