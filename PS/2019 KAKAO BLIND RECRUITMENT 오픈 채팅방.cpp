#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
typedef long long int ll;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<char, string>> vec;
    map<string, string> mp;
    for (auto s : record) {
        istringstream ss(s);
        string a, b, c; ss >> a >> b >> c;
        if (a[0] == 'E') vec.push_back({ 'E',b }), mp[b] = c;
        else if (a[0] == 'L') vec.push_back({ 'L',b });
        else mp[b] = c;
    }
    for (auto a : vec) {
        if (a.first == 'E') answer.push_back(mp[a.second]+"님이 들어왔습니다.");
        else answer.push_back(mp[a.second] + "님이 나갔습니다.");
    }
    return answer;
}

int main() {
    vector<string> vec(5);
    vec = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };    
    vector<string> ans = solution(vec);
    for (auto s : ans)
        cout << s << "\n";
    return 0;
}