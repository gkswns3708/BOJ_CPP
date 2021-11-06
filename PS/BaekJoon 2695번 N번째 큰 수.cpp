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
    int TC; cin >> TC;
    while (TC--) {
        vector<int> vec(10);
        for (auto& now : vec) cin >> now;
        sort(vec.begin(), vec.end());
        cout << vec[7] << "\n";
    }
    return 0;
}