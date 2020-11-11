#include <bits/stdc++.h>
using namespace std;

 
int main() {
    deque<char> dq_front;
    deque<char> dq_back;
    string target, s; cin >> target >> s;

    int fi, li;
    fi = 0; li = s.size() - 1;
    int  tsize = target.size();
    while (fi <= li) {
        while (fi <= li) {
            bool check = false;
            dq_front.push_back(s[fi]);
            fi++;
            if (dq_front.size() >= tsize) {
                check = true;
                for (int i = 0; i < tsize; i++) {
                    if (target[i] != dq_front[dq_front.size() - tsize + i]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) {
                for (int i = 0; i < tsize; i++)dq_front.pop_back();
                break;
            }
        }
        while (fi <= li) {
            bool check = false;
            dq_back.push_front(s[li]);
            li--;
            if (dq_back.size() >= tsize) {
                check = true;
                for (int i = 0; i < tsize; i++) {
                    if (target[i] != dq_back[i]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) {
                for (int i = 0; i < tsize; i++) dq_back.pop_front();
                break;
            }
        }
    }
    string nows;
    for (int i = 0; i < dq_front.size(); i++) nows.push_back(dq_front[i]);
    for (int i = 0; i < dq_back.size(); i++) nows.push_back(dq_back[i]);
    while(nows.find(target) <nows.length()) nows.erase(nows.find(target), tsize);
    cout << nows;
    return 0;
}
