#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

vector<tiii> vec;

int possible(int mid) {
    int cnt = 0;
    for (auto& now : vec) {
        auto [a, c, b] = now;
        c = c > mid ? mid : c;
        if(a <= mid && a <= c) cnt += (c - a) / b + 1;
    }
    return cnt;
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    vec.resize(N);
    for (auto& now : vec) {
        auto& [a, b, c] = now;
        cin >> a >> b >> c;
    }
    int l = 0, r = 2147483648;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        //cout << mid << "-mid\n";
        if (possible(mid) % 2 == 0) l = mid;
        else r = mid;
    }
    if (r == 2147483648) cout << "NOTHING\n";
    else cout << r <<" " << possible(r) - possible(r-1) << "\n";
    return 0;
}