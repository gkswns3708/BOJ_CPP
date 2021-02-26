#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int ll;
typedef unordered_map<ll, ll> ms;
ll n, s, cnt, limit;
ms mp;
ll N[41];

void binary(ll sum, ll idx, const bool& flag) {
    if (idx == limit) {
        if (flag) {
            if (mp[s - sum] > 0) cnt += mp[s - sum];
        }
        else mp[sum]++;
        return;
    }

    binary(sum + N[idx], idx + 1, flag);
    binary(sum, idx + 1, flag);
}

int main() {
    fastio;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> N[i];

    limit = n / 2;
    binary(0, 0, 0);
    limit = n;
    binary(0, n / 2, 1);
    if (s == 0) cnt--;
    cout << cnt;

    return 0;
}