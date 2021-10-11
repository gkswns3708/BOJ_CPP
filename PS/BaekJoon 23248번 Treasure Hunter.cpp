#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int m, n, k, ans;
vector<int> spot[100000+1];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int y, x; cin >> y >> x;
        spot[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) sort(spot[i].begin(), spot[i].end());
    for (int i = 1; i <= n; i++) {
        int x = 1,y = i;
        if (spot[i].empty()) continue;
        else {
            int flag = false;
            while (y <= n) {
                for (int idx = 0; idx < spot[y].size(); idx++)
                    if (spot[y][idx] >= x) {
                        x = spot[y][spot[y].size()-1];
                        spot[y].erase(spot[y].begin() + idx--,  spot[y].end());
                        flag = true;
                    }
                y++;
            }
            ans++;
        }
    }
    cout << ans;

    return 0;
}