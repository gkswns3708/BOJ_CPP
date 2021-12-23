#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N;
int fibo[40 + 1] = { 0, 5, 13 };

int cal_fibonacci(int N) {
    if (N <= 2 || fibo[N] != 0) return fibo[N];
    else return  fibo[N] = cal_fibonacci(N - 1) + cal_fibonacci(N - 2) + 1;
}

string DC(int N) {
    if (N <= 12) {
        if (N == -1 || "Messi Gimossi"[N] == ' ') return "Messi Messi Gimossi"
        else {
            string s_ans; s_ans.push_back("Messi Gimossi"[N]);
            return s_ans;
        }
    }
    else for (int i = 40; i >= 2; i--) if (N >= cal_fibonacci(i)) return DC(N - fibo[i] - 1);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N; N--;
    cout << DC(N);
    return 0;
}