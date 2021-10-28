#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

queue<string> que[100 + 1];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    cin.ignore();
    for (int i = 0; i <= N; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> temp) que[i].push(temp);
    }
    while (!que[N].empty()) {
        auto now = que[N].front();
        que[N].pop();
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (!que[i].empty() && que[i].front() == now) {
                flag = true;
                que[i].pop();
                break;
            }
        }
        if (!flag) {
            cout << "Impossible";
            exit(0);
        }
    }
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (!que[i].empty())flag = false;
    }
    if (flag)cout << "Possible";
    else cout << "Impossible";
    return 0;
}