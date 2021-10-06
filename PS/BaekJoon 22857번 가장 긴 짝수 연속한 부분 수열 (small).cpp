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
    int N, K; cin >> N >> K;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i], vec[i] &= 1;
    int ans = 0;
    for (int l = 0, r = 0, sum = 0; l < N;) {
        while (r < N && sum + vec[r] <= K) sum += vec[r++];
        ans = max(ans, r - l - sum);
        sum -= vec[l++];
    }
    cout << ans;
    return 0;
}