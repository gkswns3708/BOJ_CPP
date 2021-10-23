#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int R, C, H, W;

int arr[3000 + 1][3000 + 1];
int psum[3000 + 1][3000 + 1];

bool check(int val) {
    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
        psum[i][j] = arr[i][j] > val ? 1 : arr[i][j] == val ? 0 : -1;
        psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
    for (int i = H; i <= R; i++) for (int j = W; j <= R; j++) {
        int now = psum[i][j] - psum[i - H][j] - psum[i][j - W] + psum[i - H][j - W];
        if (now < 0) return true;
    }
    return false;
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> H >> W;
    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) cin >> arr[i][j];
    int l = 0, r = R * C;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (!check(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
    return 0;
}