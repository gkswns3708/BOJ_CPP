#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int n, k;
vector<int> vec(10000 + 1);
int cnt_out[10000 + 1];
int cnt_in[10000 + 1];
int kind_out = 0;
int kind_in = 0;

bool check(int now,bool flag) {
    if (flag){
        if (--cnt_out[now] == 0) kind_out--;
        if (++cnt_in[now] == 1) kind_in++;    
    }
    else {
        if (++cnt_out[now] == 1) kind_out++;
        if (--cnt_in[now] == 0) kind_in--;
    }   
    return kind_out == k && kind_in == k;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        cnt_out[vec[i]]++;
    }
    kind_out = k;
    int l, r, ans = n + 1;
    l = -1 ,r = 0;
    cnt_in[vec[0]]++;
    cnt_out[vec[0]]--;
    kind_in = 1;
    kind_out = cnt_out[vec[0]] == 0 ? kind_out - 1 : kind_out;
    queue<int> que;
    while (1) {
        if (kind_in < k) { //이미 안이 종류가 다 참 r을 오른쪽으로 옮김
            if (++r == n) break;
            if (check(vec[r], true)) ans = min(ans, r - l);   
        }
        else if (check(vec[++l], false)) ans = min(ans, r - l);      
    }
    cout << ((ans == n + 1)? 0 : ans)<< "\n";

    return 0;
}