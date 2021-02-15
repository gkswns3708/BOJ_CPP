#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int board[20][20];
bool visit[20][20];
vector<pair<int, int>> pick;
int dr[] = { 0,1,-1, 0 };
int dc[] = { 1,0, 0,-1 };
int ans = 0;
bool OOB(int r, int c) {
    return (r < 0 || r >= N || c < 0 || c >= M);
}
int floodFill(int r, int c) {
    int killing = 0;
    queue<pair<int, int>> q;
    q.emplace(r, c);
    visit[r][c] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        killing++; //검은돌 개수 카운팅
        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] == 0) return -1; // 검은돌 주변에 빈공간 있으면 바로 탈락
            if (!visit[nx][ny] && board[nx][ny] == 2) {
                q.emplace(nx, ny);
                visit[nx][ny] = true;
            }
        }
    }
    return killing;
}
int kill() {
    memset(visit, false, sizeof(visit));
    int killed = 0;

    for (auto [r, c] : pick) {
        for (int i = 0; i < 4; ++i) { // 내가 현재 돌 놓는곳 기준으로 4방향 모두 검사
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!OOB(nr, nc) && !visit[nr][nc] && board[nr][nc] == 2) { // 방문하지 않은 검은돌 있으면
                int ff = floodFill(nr, nc);
                if (ff < 0) return -1;
                else killed += ff;
            }
        }
    }
    return killed;
}
void dfs(int cnt, int idx) {
    if (cnt >= 2) { //두개씩 선택
        ans = max(kill(), ans);
        return;
    }
    if (idx >= N * M - 1) return;

    dfs(cnt, idx + 1);

    if (board[(idx + 1) / M][(idx + 1) % M] != 0) return;

    pick.emplace_back((idx + 1) / M, (idx + 1) % M);
    board[(idx + 1) / M][(idx + 1) % M] = 3;
    dfs(cnt + 1, idx + 1);
    board[(idx + 1) / M][(idx + 1) % M] = 0;
    pick.pop_back();
}
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    dfs(0, -1);
    cout << ans << '\n';
    return 0;
}