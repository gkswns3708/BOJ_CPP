#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

double N, L, W, H, ans;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> W >> H;
    double l = 0, r = (int)1e9;
    for(int i = 0 ; i < 10000;i++) {
        double mid = double(l + r) / 2.0;
        double sum = int(L / mid) * int(W / mid) * int(H / mid);
        if (sum >= N) l = mid;
        else r = mid;
    }
    cout <<fixed <<setprecision(15)<< l;
    return 0;
}