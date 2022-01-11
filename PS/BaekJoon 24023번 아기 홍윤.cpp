#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, K;
bool flag;
vector<int> vec;
bitset<32> bs;
bitset<32> check;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    check = K;
    vec.resize(N);
    for (auto& now : vec) cin >> now;
    int st = 0, ed = 0;
    bs = 0;
    for (ed = 0; ed < N; ed++) {
        bs |= vec[ed];
        if (bs == check) {
            cout << st + 1 << " " << ed + 1 << "\n";
            flag = true;
            break;
        }
        for (int i = 0; i < 32; i++) {
            if (check[i] == 0 && bs[i] == 1) {
                st = ed + 1;
                bs = 0;
                break;
            }
        }
    }
    if (!flag) cout << -1 << "\n";
    return 0;
}