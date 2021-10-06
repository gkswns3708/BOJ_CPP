#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int dp[1000 + 1];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC; cin >> TC;
    for(int i = 1; i <= 1000; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i - 1; j++) {
            if ((i - j) & 1) continue;
            dp[i] += dp[i - j >> 1];
        }
    }
    while (TC--) {
        int now; cin >> now;
        cout << dp[now] << "\n";
    }
    return 0;
}