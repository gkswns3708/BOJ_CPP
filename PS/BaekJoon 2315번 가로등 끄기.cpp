#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, M;
vector<pii> vec;
vector<int> p_sum;
int dp[1000 + 3][1000 + 3][2]; // [i][j][flag] : i~j��° ���ε��� ��� ������, ���� ��ġ�� 0�̸� i 1�̸� j�̴�.

int DP(int l, int r, int flag) {
    if (l == 1 && r == N) return 0; // �� �� ���ε� ���� x
    int& ret = dp[l][r][flag];
    if (ret != -1) return ret;

    int pos = flag ? r : l;
    int light = p_sum[N] - p_sum[r] + p_sum[l - 1]; //���� �����ִ� ���ε��� ���� �Һ�
    if (l > 1) {
        int tmp = DP(l - 1, r, 0) + (vec[pos].first - vec[l - 1].first) * light;
        if (ret == -1 || tmp < ret) ret = tmp;
    }
    if (r < N) {
        int tmp = DP(l, r + 1, 1) + (vec[r + 1].first - vec[pos].first) * light;
        if (ret == -1 || tmp < ret) ret = tmp;
    }
    return ret;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    vec.resize(N + 1), p_sum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i].first >> vec[i].second;
        p_sum[i] = p_sum[i - 1] + vec[i].second;
    }
    memset(dp, -1, sizeof(dp));
    cout << DP(M, M, 0); //M,M 1�� ���� ���ص� ��.

    return 0;
}