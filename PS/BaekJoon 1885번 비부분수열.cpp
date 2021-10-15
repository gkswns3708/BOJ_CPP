#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int n, k,cnt, ans;
bitset<10001> visited;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!visited[a]) cnt += visited[a] = true;
        if (cnt == k) {
            ans++, cnt = 0;
            visited.reset();
        }
    }
    cout << ans + 1;
    return 0;
}