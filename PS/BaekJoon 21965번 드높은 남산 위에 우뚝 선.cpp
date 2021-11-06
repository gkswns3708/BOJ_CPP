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
    bool flag = false;
    vector<int> vec(N);
    for (auto& now : vec) cin >> now;

    int max_value = *max_element(vec.begin(), vec.end());
    vector<int>::iterator max_pos = max_element(vec.begin(), vec.end());
    if ((unique(vec.begin(), vec.end()) == vec.end()) && 
        is_sorted(vec.begin(), max_pos) && 
        is_sorted(max_pos, vec.end(), [](int x, int y) {return y < x; })) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}