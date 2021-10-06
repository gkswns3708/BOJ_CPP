#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, K, x, y;
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };

double dp[50 + 1][50 + 1][50 + 1];

bool OOB(int x, int y) {
    if (x >= 1 && x <= N && y > 0 && y <= N) return true;
    else return false;
}

double DFS(int x, int y, int k) {
    if (k >= K) return (double)1;
    double& ret = dp[x][y][k];
    if (ret != (double)0) return ret;
    ret = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (OOB(nx, ny)) ret += DFS(nx, ny, k + 1) / 8;
    }
    return ret;
}

void input() {
    cin >> N >> x >> y >> K;
}

void solution() {
    cout << fixed << setprecision(30) << DFS(x, y, 0);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}