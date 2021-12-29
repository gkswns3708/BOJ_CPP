#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

vector<tiii> vec;
int N, A, B;

bool cmp(tiii a, tiii b) {
    auto [n1, A1, B1] = a;
    auto [n2, A2, B2] = b;
    return abs(A1-B1) > abs(A2-B2);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        int N, A, B; cin >> N >> A >> B;
        if (N == 0 && A == 0 && B == 0) exit(0);
        vec.resize(N);
        for (auto& now : vec) {
            auto& [n, a, b] = now;
            cin >> n >> a >> b;
        }
        sort(vec.begin(), vec.end(), cmp);
        int ans = 0;
        for (auto now : vec) {
            auto [n, a, b] = now;
            if (a < b)
                if (n > A)  ans += A * a, ans += b * (n - A), A = 0, B -= (n - A);
                else  ans += n * a, A -= n;
            else if (a == b)  ans += n * a;// 어차피 남은거로 진행되고, 무조건 됨
            else
                if (n > B) ans += B * b, ans += a * (n - B), B = 0, A -= (n - B);
                else ans += n * b, B -= n;
        }
        cout << ans << "\n";
    }
    return 0;
}