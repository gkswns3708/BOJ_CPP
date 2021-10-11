#include <bits/stdc++.h>
#include <unordered_set>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, A, B, cnt;
inline size_t key(int i, int j) { return (size_t)i << 32 | (int)j; }
unordered_set<int> dot;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        dot.insert(key(x, y));
    }
    for (auto& now : dot) {
        int x = now >> 32;
        int y = ((1LL << 32) - 1) & now;
        if (dot.find(key(x + A, y)) != dot.end() && dot.find(key(x, y + B))!= dot.end() && dot.find(key(x + A, y + B)) != dot.end()) cnt++;
    }
    cout << cnt;
    return 0;
}