#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

vector<int> white, black;

int dp[1000 + 1][15 + 1][15 + 1];

int DFS(int wcnt, int bcnt, int pos) {
    if (wcnt == 0 && bcnt == 0 || pos == white.size()) return 0;
    int& ret = dp[pos][wcnt][bcnt];
    if (ret != -1) return ret;
    if (wcnt > 0) ret = max(ret, DFS(wcnt - 1, bcnt, pos + 1) + white[pos]);
    if (bcnt > 0) ret = max(ret, DFS(wcnt, bcnt - 1, pos + 1) + black[pos]);
    ret = max(ret, DFS(wcnt, bcnt, pos + 1));
    return ret;
}

void input() {
    int w, b;
    while (cin >> w >> b) white.push_back(w), black.push_back(b);
    memset(dp, -1, sizeof dp);
}

void solution() {
    cout << DFS(15, 15, 0);
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