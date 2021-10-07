#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans(right - left + 1);
    for (int i = left; i <= right; i++) {
        int y = i / n;
        int x = i % n;
        if (x < y) ans[i - left] = y + 1;
        else ans[i - left] = x + 1;
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> ans = solution(4,7,14);
    for (auto& now : ans)
        cout << now << " ";
    return 0;
}