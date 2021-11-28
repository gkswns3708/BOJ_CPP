#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w; cin >> n >> w;
    vector<int> vec(n);
    for (auto& now : vec) cin >> now;
    int tmp = 0, cnt = 0;
    for (auto& now : vec) {
        if (tmp + now >= w) cnt++, tmp = 0;
        else tmp += now;
    }
    cout << cnt << "\n";
    return 0;
}