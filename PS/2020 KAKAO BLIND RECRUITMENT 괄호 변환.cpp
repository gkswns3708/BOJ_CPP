#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string solution(string s) {
    if (s == "") return "";
    bool check = true;
    int cnt, pos;
    cnt = pos = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') cnt++;
        else if (s[i] == ')') cnt--;
        if (check && cnt == 0) {
            pos = i;
            break;
        }
    }
    string u, v;
    u = s.substr(0, pos + 1);
    if(pos + 1 < s.size()) v = s.substr(pos + 1);

    check = true;
    cnt = 0;
    for (int i = 0; i < u.length(); i++) {
        if (u[i] == '(') cnt++;
        else if (u[i] == ')') cnt--;
        if (cnt < 0) {
            check = false;
            break;
        }
    }
    if (check) return u + solution(v);
    else {
        u.erase(0, 1); u.pop_back();
        for (auto& a : u) {
            if (a == '(') a = ')';
            else a = '(';
        }
        return '(' + solution(v) + ')' + u;
    }
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    cout << solution(s);
    return 0;
}
