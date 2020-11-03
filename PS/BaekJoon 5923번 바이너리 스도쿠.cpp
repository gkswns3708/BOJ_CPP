#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int INF = 1e9;
int dp[9][9][1 << 9][1 << 3][2];
bool board[9][9];

int solve(int i, int j, int mi, int mj, bool check) {
    if (i == 9) return mi ? INF : 0;
    if (j == 9) return check || i % 3 == 2 && mj ? INF : solve(i + 1, 0, mi, mj, 0);
    int& ret = dp[i][j][mi][mj][check];
    if (ret != -1) return ret;
    ret = !board[i][j] + solve(i, j + 1, mi ^ 1 << j, mj ^ 1 << j / 3, !check);
    ret = min(ret, board[i][j] + solve(i, j + 1, mi, mj, check));
    return ret;
}

int main() {
    fastio;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) { char c; cin >> c; board[i][j] = c - '0'; }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0, 0, 0) << '\n';
}