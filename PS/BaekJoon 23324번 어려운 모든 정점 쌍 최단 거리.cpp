#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

vector<int> vec[100000 + 1];
bool visitedA[100000 + 1];
bool visitedB[100000 + 1];
int N, M, K;
int st, ed;
int cntA;

bool BFS(bool* visited_arr, int st,int ed) {
    queue<int> que;
    visited_arr[st] = true;
    cntA++;
    for (auto& nxt : vec[st]) {
        if (nxt == ed) continue;
        visited_arr[nxt] = true, cntA++, que.push(nxt);
    }
    while (!que.empty()) {
        auto now = que.front();
        que.pop();
        for (auto& nxt : vec[now]) {
            if (ed == nxt) return true;
            if (visited_arr[nxt] != true) visited_arr[nxt] = true, cntA++,que.push(nxt); 
        }
    }
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= M;i++) {
        int to, from; cin >> to >> from;
        vec[to].push_back(from);
        vec[from].push_back(to);
        if (i == K) st = to, ed = from;
    }
    if (BFS(visitedA, st, ed)) cout << "0\n";
    else cout << cntA * (N - cntA) << "\n";
    return 0;
}