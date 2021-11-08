#include <bits/stdc++.h>
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N;

bool visited[512 + 1][512 + 1];

struct Converter { //0xdd -> int
    int conv[128];
    Converter() {
        for (int i = 0; i < 16; i++)
            conv["0123456789abcdef"[i]] = i;
    }
    int operator() (const string& s) {
        return conv[s[2]] << 4 | conv[s[3]];
    }
} Conv;



void input() {
    vector<string> s(11);
    for (int i = 0; i < 11; i++) cin >> s[i];
    N = stoi(s[2]);    
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        vector<int> vec;
        for (int j = 0; j < tmp.length(); j+=5) vec.push_back(Conv(tmp.substr(j, 4)));
        for (int j = 0; j < vec.size(); j++) for (int k = 0; k < 8; k++) if (vec[j] & 1 << k) visited[i][j * 8 + k] = 1;
    }
    string tmp;
    cin >> tmp;
}

void DC(int y, int x, int len) {
    bool flag = 1;
    for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) if (visited[i + y][j + x] != visited[y][x]) flag = 0;
    if (flag) cout << (visited[y][x] ? 'B' : 'W');
    else {
        cout << "Q";
        len /= 2;
        DC(y, x, len);
        DC(y, x + len, len);
        DC(y + len, x, len);
        DC(y + len, x + len, len);
    }
    
}

void solution() {
    cout << N << "\n";
    DC(0, 0, N);
}

int32_t main()
{
    input();
    solution();
    return 0;
}