#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int minlength = s.length();
    for (int i = 1; i <= s.length()/2; ++i) {
        int count = 1;
        int nowlength = s.length();
        string prestr =s.substr(0,i);
        for (int j = i; j + i<= s.length(); j+=i) {
            string nowstr = s.substr(j, i);
            if (prestr == nowstr) {
                count++;
            }
            else {
                if (count > 1) nowlength +=to_string(count).length();
                nowlength -= i * (count-1);
                count = 1;
                prestr = nowstr;
            }
        }
        if (count > 1) {
            nowlength -= i * (count-1);
            nowlength += to_string(count).length();
        }
        minlength = min(minlength, nowlength);
    }
    cout << minlength<<"";
    return 0;
}
