#include <bits/stdc++.h>
using namespace std;

double arr[100000+1];
int N, M;
bool check(double mid) {
    double sum = 0,mn = 0,sum2 = 0;
    for (int i = 0; i < M - 1; i++) sum += arr[i] - mid;
    for (int i = M - 1; i < N; i++) {
        sum += arr[i] - mid;
        if (sum2 < mn) mn = sum2;
        if (sum - mn >= 0) return true;
        sum2 += (arr[i - M + 1] - mid);
    }
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    double l = 0, r = 2000;
    for(int i = 0 ; i < 64;i++){
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << (int)((l + r)*500+0.0001) << "\n";
    return 0;
}