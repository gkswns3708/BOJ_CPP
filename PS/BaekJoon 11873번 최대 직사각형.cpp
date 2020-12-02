#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        int r = 0, h[1001] = { 0, }, stk[1001], top;
        for (int i = 1; i <= N; i++) {
            top = 0;
            stk[0] = 0;
            for (int j = 1; j <= M; j++) {
                int x; cin >> x;
                h[j] = (h[j] + 1) * x;
                while (h[stk[top]] > h[j]) r = max(r, (j - stk[top - 1] - 1) * h[stk[top--]]);
                stk[++top] = j;
            }
            while (top) r = max(r, (M - stk[top - 1]) * h[stk[top--]]);
        }
        cout << r << "\n";
    }
    return 0;
}