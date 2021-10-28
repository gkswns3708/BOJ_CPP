#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;
int K; 

vector<int> width;
vector<int> height;
vector<int> temp;

void input() {
    cin >> K;
    for (int i = 0; i < 6; i++) {
        int dir, len; cin >> dir >> len;
        if (dir == 1 || dir == 2) width.push_back(len);
        else height.push_back(len);
        if (i == 2 || i == 3) temp.push_back(len);
    }
}

void solution() {
    sort(width.begin(), width.end());
    sort(height.begin(), height.end());
    cout << temp[0] << " " << temp[1] << "\n";
    cout << (width.back() * height.back() - temp[0]*temp[1])*K << "\n";
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