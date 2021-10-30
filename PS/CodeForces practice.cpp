#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int n, k;


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> k;
        vector<int> vec(n);
        vector<int> cntvec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        int tempk = k;
        int pos = 0;
        int createnum = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (int(pow(10, vec[i + 1] - vec[i])) - 1 <= tempk) {
                tempk -= int(pow(10, vec[i + 1] - vec[i])) - 1;
                pos = i + 1; 
                cntvec[i] = int(pow(10, vec[i + 1] - vec[i])) - 1;
            }
            else break;
        }
        string s; 
        for (int i = 0; i <= vec[pos] - 1; i++) s.push_back('9');      
        if(!s.empty()) ans += stoll(s);
        ans += (tempk + 1) * int(pow(10, vec[pos]));
        cout << ans << "\n";

    }
    return 0;
}