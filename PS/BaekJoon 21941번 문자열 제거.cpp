#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

unordered_map<string, bool> mp;
string s;
int M, ans;
pair<string, int> A[100 + 1];
int dp[1000 + 1];

int DFS(int idx){
    if (idx >= s.length()) return 0;
    if (dp[idx] != -1)return dp[idx];
    int maxvalue = 0;
    for (int i = 0; i < M; i++) {
        int pos = idx;
        while (1) {
            pos = s.find(A[i].first, pos);
            if (pos != string::npos) 
                maxvalue = max(maxvalue, DFS(pos++ + A[i].first.length()) + A[i].second);
            else break;
        }
    }
    maxvalue = max(maxvalue, 1 + DFS(idx + 1));
    return dp[idx] = maxvalue;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> M;
    for (int i = 0; i < M; i++)
        cin >> A[i].first >> A[i].second;
    ans = s.length();
    memset(dp, -1, sizeof(dp));
    cout << DFS(0);
    return 0;
}