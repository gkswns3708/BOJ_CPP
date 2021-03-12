#include <string>
#include <iostream>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    string s = "", temp;
    while (getline(cin, temp)) {
        if (temp == "") continue;
        if (temp.back() != ' ') temp.push_back(' ');
        s += temp;
        if (temp == "1 ") break;
    }
    regex r(R"(\s?([^\s\t]+)(\s.+)?)");
    vector<string> v;
   for(auto it  = sregex_iterator(s.begin(), s.end(), r); it != sregex_iterator();it++){
       v.push_back((*it)[1]);
       v.push_back((*it)[2]);
    }
    int length = 0;
    cout << v.size() << "\n";
    for (auto now : v) {
        cout << now << "-regex\n";
    }
    for (auto str : v) {
        if (str == "<br>") {
            cout << "\n";
            continue;
        }
        else if (str == "<hr>") {
            if (length != 0) cout << '\n';
            for (int i = 0; i < 80; i++) cout << '-';
            cout << '\n';
            continue;
        }
        else {
            cout << str;
            if (length + str.size() > 80)   length = 0, cout << '\n';           
            else cout << ' ', length += str.size();
        }
    }
    return 0;
}