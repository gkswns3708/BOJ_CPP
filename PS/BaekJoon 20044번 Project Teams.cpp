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
    int N; cin >> N;
    vector<int> vec(2 * N);
    for (auto& now : vec) cin >> now;
    sort(vec.begin(), vec.end());
    int ans = 987654321;
    for (int i = 0; i < N; i++) {
        int st = vec[i], ed = vec[2 * N - 1 - i];
        ans = min(ans, st + ed);
    }
    cout << ans;
    return 0;
}