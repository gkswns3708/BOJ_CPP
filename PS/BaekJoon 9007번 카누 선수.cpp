#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define INF 987654321
using namespace std;

int k,n,ans; 
int flag = -1;
vector<int> vec[4];
vector<int> sum1,sum2;

void input() {
    ans = INF;
    cin >> k >> n;
    for (int i = 0; i < 4; i++) {
        vec[i].clear(), vec[i].resize(n);
        for (auto& now : vec[i]) cin >> now;
    }
}
void solution() {
    sum1.clear(), sum2.clear();
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sum1.push_back(vec[0][i] + vec[1][j]);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sum2.push_back(vec[2][i] + vec[3][j]);
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    for (int i = 0; i < sum1.size(); i++) {
        int goal = k - sum1[i];
        int target1 = lower_bound(sum2.begin(), sum2.end(), goal) - sum2.begin();
        int target2 = target1 - 1;
        if (target1 != sum2.size()) {//작은 쪽에서 이미 작은 값을 찾았을 때
            int gap = abs(k - sum1[i] - sum2[target1]);
            if (abs(ans - k) > gap) ans = sum1[i] + sum2[target1];
            if (abs(ans - k) == gap) ans = min(ans, sum1[i] + sum2[target1]);
        }
        if (target2 >= 0) {
            int gap = abs(k - sum1[i] - sum2[target2]);
            if (abs(ans - k) > gap) ans = sum1[i] + sum2[target2];
            if (abs(ans - k) == gap) ans = min(ans, sum1[i] + sum2[target2]);
        }
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        input();
        solution();
    }
    return 0;
}