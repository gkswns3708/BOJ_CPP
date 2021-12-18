#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N;
vector<pii> vec;

bool cmp(pii a, pii b) {
    auto [aa, ab] = a;
    auto [ba, bb] = b;
    if (aa == 0) return 0;
    else if (ba == 0) return 1;
    else if (ab == 0 && bb == 0) return aa < ba;
    return ab * ba < aa* bb;
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vec.resize(N);
    for (auto& now : vec) cin >> now.first >> now.second;
    sort(vec.begin(), vec.end(), cmp);
    int ans = 0;
    for (auto& now : vec) {
        auto [f, s] = now;
        ans += ans * f + s;
        ans %= 40000;
    }
    cout << ans;
    return 0;
}