#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int cnt[256];
int conv[256];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; char a; cin >> n >> a;
    string s; cin >> s;
    for (auto& now : s) cnt[now]++;
    int diff = distance(cnt, max_element(cnt, cnt + 256)); // Â÷ÀÌ
    for (auto& now : s) {
        now = (now - diff+26) % 26;
        cout << char(now + 'A');
    }

    return 0;
}