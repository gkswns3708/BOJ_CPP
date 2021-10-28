#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;


string arr[100 + 1];
string ansarr[100 + 1];
bool visited[100 + 1][100 + 1];
vector<pii> parents[100 + 1][100 + 1];
int maxdist = 0;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool possible(int y, int x) {
    if (y >= 0 && x >= 0 && y < 100 && x < 100 & !visited[y][x]) return true;
    else return false;
}

void initarr(pii pos) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == 0 || i == 99 || j == 0 || j == 99) visited[i][j] = true;
            else if (arr[i][j] == 'X') visited[i][j] = true;
        }
    }
    visited[pos.first][pos.second] = false;
}

int BFS(int a, int b) {
    queue<pii> que;
    que.push({a, b});
    visited[a][b] = 1;
    int dist = 0;
    while (!que.empty()) {
        int sz = que.size();
        while (sz--) {
            pii now = que.front();
            int y = now.first;
            int x = now.second;
            que.pop();
            arr[y][x] = '.';
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (possible(ny,nx)) {
                    visited[ny][nx] = 1;
                    que.push({ ny,nx });
                    parents[ny][nx].push_back({ y,x });
                }
            }
        }
        dist++;
    }
    return dist;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 100; i++) cin >> arr[i];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == 0 || i == 99 || j == 0 || j == 99) {
                initarr({ i,j });
                int tmp = BFS(i, j);
                if (maxdist < tmp) {
                    for (int i = 0; i < 100; i++) ansarr[i] = arr[i];
                    maxdist = tmp;
                }
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        cout << ansarr[i] << "\n";
    }
    return 0;
}