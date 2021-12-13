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
        int n; cin >> n;
        vector<int> odd,even;
        for (int i = 0; i < n; i++) {
            int now; cin >> now;
            if (now % 2) odd.push_back(now);
            else even.push_back(now);
        }
//      sort(odd.begin(), odd.end());
//      sort(even.begin()), even.end());
        for (int i = 0; i < n / 2; i++) {

        }
    }
    return 0;
}