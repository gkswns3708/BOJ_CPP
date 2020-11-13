#include <bits/stdc++.h>
using namespace std;

int N;
int         dp[100000 + 10][30];
bool        visited[100000 + 10];
int         depth[100000 + 10];
vector<int> g[100000+10];
//parent, depth

void DFS(int pos, int d) {
    visited[pos] = true;
    depth[pos] = d;
    for (auto i : g[pos]) {
        if (!visited[i]) {
            dp[i][0] = pos;
            DFS(i, d + 1);
        }
    }
}


void make_tree() {
    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= N; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
}

int lca(int first,int second) {
    //first¸¦ ´õ ³·Àº °É·Î ¸¸µê.
    if (depth[first] < depth[second]) swap(first, second);
    int gap = depth[first] - depth[second];
    for (int i = 0; gap; i++) {
        if (gap & 1) first = dp[first][i];
        gap >>= 1;
    }
    if (first == second) return first;
    for (int i = 29; i >= 0; i--) {
        if (dp[first][i] != dp[second][i]) {
            first = dp[first][i];
            second = dp[second][i];
        }
    }
    return dp[first][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int from, to; cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    DFS(1, 0);
    make_tree();
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout <<lca(a, b)<<"\n";
    }
    return 0;
}
