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
    vector<string> s(N);
    for (auto& now : s) cin >> now;
    if (is_sorted(s.begin(), s.end())) cout << "INCREASING";
    else if (is_sorted(s.begin(), s.end(), greater<>())) cout << "DECREASING";
    else cout << "NEITHER";
    return 0;
}