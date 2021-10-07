#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int solution(int N) {
    int ans = (N / 6) * (N / 6 + 1) * 3 + 1;
    if (N % 6) ans += (N / 6) + (N / 6 + 1) * (N % 6 - 1);
    return ans;
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    cout << solution(N) << "\n";
    return 0;
}