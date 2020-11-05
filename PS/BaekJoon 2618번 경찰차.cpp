#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define Y first
#define X second
int N,W;
vector<pair<int, int>> incident;
deque<pair<int, int>> car1, car2;
vector<int> ans;
int dp[1001][1001];
int func(int c1,int c2) {
    if (c1 == W || c2 == W)return 0;
    int& ref = dp[c1][c2];
    if (ref != -1) return ref;

    int nowpos = max(c1, c2) + 1;
    int dist1 = abs(car1[c1].first - car1[nowpos].first) + abs(car1[c1].second - car1[nowpos].second);
    int n1 = func(nowpos, c2) + dist1;

    int dist2 = abs(car2[c2].first - car2[nowpos].first) + abs(car2[c2].second - car2[nowpos].second);
    int m1 = func(c1, nowpos) + dist2;

    return ref = min(n1, m1);
}

void tracking(int c1,int c2) {
    if (c1 == W || c2 == W)
        return;
    int nowpos = max(c1, c2) + 1;
    int dist1 = abs(car1[c1].first - car1[nowpos].first) + abs(car1[c1].second - car1[nowpos].second);
    int n1 = dp[nowpos][c2] + dist1;

    int dist2 = abs(car2[c2].first - car2[nowpos].first) + abs(car2[c2].second - car2[nowpos].second);
    int m1 = dp[c1][nowpos] + dist2;
    if (n1 < m1) {
        ans.push_back(1);
        tracking(nowpos, c2);
    }
    else {
        ans.push_back(2);
        tracking(c1, nowpos);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> W;
    car1.push_back({ 1,1 });
    car2.push_back({ N,N });
    for (int i = 0; i < W; i++) {
        int num1, num2; cin >> num1 >> num2;
        car1.push_back({ num1,num2 });
        car2.push_back({ num1,num2 });

    }
    for(int i = 0 ; i < 1001;i++)
        for(int j = 0 ; j < 1001;j++)
            dp[i][j] = -1;
    
    cout << func(0, 0)<<"\n";
    tracking(0, 0);
    for (auto a : ans) cout << a << "\n";
    return 0;
}