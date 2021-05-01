#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0, lr = 0, numl = 0, numr = 0, maxl = 0, maxr = 0;
    bool left = false, right = false;
    for (int i = 1; i < name.size(); i++) {
        if (!right && name[i] != 'A') right = true, numl = i;
        if (!left && name[name.size() - i] != 'A') left = true,numr = i;      
    }
    for (int i = 1; i <= name.size()/2; i++) {
        if ( name[i] != 'A')  maxr = i;       
        if (name[name.size() - i] != 'A') maxl = i;
    }
    for (int i = 0; i < name.size(); i++) if (name[i] != 'A') answer += min(abs(name[i] - 'A'), abs(26 - name[i] + 'A'));   
    if (right || left) answer += min((int)name.size()- max(numl, numr),min(maxl,maxr)*2 + max(maxl,maxr));
    return answer;
}

int main() {
    solution("ABABAAAAAAABA");
}