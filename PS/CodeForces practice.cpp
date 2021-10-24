#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int _gcd(int a, int b) {
    return b == 0 ? a : _gcd(b, a % b);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        int sum = 0;
        vector<bool> pm;
        for (int i = 0; i < n - 1; i++) {
            if (vec[i] >= 0) {
                if (sum < 0) sum += vec[i], pm.push_back(true);
                else sum -= vec[i], pm.push_back(false);
            }
            else {
                if (sum < 0) sum -= vec[i], pm.push_back(false);
                else sum += vec[i], pm.push_back(true);
            }
        }
        int tempsum;
        if (sum < 0) tempsum = -sum;
        else tempsum = sum;
        int now_gcd;
        if (tempsum >= vec[n - 1])now_gcd = _gcd(tempsum, vec[n - 1]);
        else now_gcd = _gcd(vec[n - 1], tempsum);
        for (auto now : pm) {
            if (now) cout << 1 * vec[n-1] / now_gcd << " ";
            else cout << -1 * vec[n - 1] / now_gcd << " ";
        }
        cout << -sum / now_gcd << "\n";
    }
    return 0;
}