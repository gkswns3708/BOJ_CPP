#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int  k, n, m;
    cin >> k >> n;
    long long score = n, cnt = 0;
    for (long long i = 0; i < k; ++i) {
        cin >> m;
        if (score - m >= 0) {
            score -= m;
        }
        if (i == k - 1 && !score) {
            ++cnt;
            score = 0;
        }
        else if (!score) {
            ++cnt;
            score = n;
        }
    }
    cout << cnt << "\n" << score;
    return 0;
}
