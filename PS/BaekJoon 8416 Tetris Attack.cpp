#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, top;
vector<bool> visited;
vector<pii> stk;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<int> answer;
    visited.resize(N * 2, false);
    stk.resize(N * 2);
    for (int i = 0; i < N * 2; i++) {
        int now; cin >> now;
        if (!visited[now]) { // 등장하지 않았으면 일단 쌓음
            top++;
            stk[top] = { now, top };
            visited[now] = 1;
        }
        else {
            vector<pii> tmp;
            while (stk[top].first != now) {
                tmp.push_back({ stk[top].first, stk[top].second - 1 });
                answer.push_back(stk[top].second);
                top--;
            }
            top--;
            while (!tmp.empty()) {
                auto [f, s] = tmp.back();
                tmp.pop_back();
                stk[++top] = { f, s };
            }
        }
    }
    cout << answer.size() << "\n";
    for (auto now : answer) cout << now << "\n";
    return 0;
}