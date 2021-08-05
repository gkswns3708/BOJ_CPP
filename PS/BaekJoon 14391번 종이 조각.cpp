#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m, answer = 0, dx[2] = { 1, 0 }, dy[2] = { 0, 1 };
bool visit[5][5] = { false };
char graph[5][5];

void dfs(int x, int y, int cnt, int psum) {
    if (cnt == n * m) {
        answer = max(answer, psum);
        return;
    }
    if (visit[x][y]) dfs(x + (y + 1) / m, (y + 1) % m, cnt, psum);
    else {
        vector<pii> v;
        string s = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[i] * j, ny = y + dy[i] * j;
                if (nx == n || ny == m || visit[nx][ny]) break;
                visit[nx][ny] = true;
                s += graph[nx][ny];
                v.push_back(make_pair(nx, ny));
                dfs(x + (y + 1) / m, (y + 1) % m, cnt + 1 + j, psum + stoi(s));
            }
            while (!v.empty()) {
                int nx = v.back().first, ny = v.back().second;
                s.pop_back();
                visit[nx][ny] = false;
                v.pop_back();
            }
        }
    }
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) graph[i][j] = s[j];
    }
}

int main() {
    init();
    dfs(0, 0, 0, 0);
    cout << answer << '\n';
}