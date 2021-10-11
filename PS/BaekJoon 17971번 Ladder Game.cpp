#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

vector<tiii> vec;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    for (int line = 1; line < N; line++) {
        int val, idx = 1;
        while (cin >> val && val != 0) vec.push_back({val,line,idx++});
    }
    sort(vec.begin(), vec.end());
    vector<int> output(N + 1);
    for (int i = 1; i <= N; i++) output[i] = i;
    for (auto& now : vec) {
        auto [val, line, idx] = now;
        swap(output[line], output[line + 1]);
    }
    reverse(vec.begin(), vec.end());
    vector<pii> ans;
    for (auto& now : vec) {
        auto [val, line, idx] = now;
        if (output[line] > output[line + 1]) ans.push_back({ line,idx }), swap(output[line], output[line + 1]);
    }
    cout << ans.size() << "\n";
    for (auto& now : ans) cout << now.first << " " << now.second << "\n";
    return 0;
}