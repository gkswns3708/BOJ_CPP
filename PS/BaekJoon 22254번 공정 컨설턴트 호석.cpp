#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, X, total;
vector<int> vec;

bool possible(int mid) {
    if ((total / mid) > X) return false;   
    else {
        priority_queue<int, vector<int>, greater<int>> pq;
        int cnt = 0;
        for (auto& now : vec) {
            if (++cnt <= mid) { 
                pq.push(now); 
                if (now > X) return false;    
                continue;
            }
            else {
                int top = pq.top();pq.pop();
                if (top + now > X) return false;
                else pq.push(top + now);
                
            }
        }
    }
    return true;
}


void input() {
    cin >> N >> X;
    vec.resize(N);
    for (auto& now : vec) cin >> now, total += now;
}

void solution() {
    int l = 0, r = N;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (possible(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}