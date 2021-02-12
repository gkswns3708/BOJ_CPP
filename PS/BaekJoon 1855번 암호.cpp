#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char arr[10][20];
int main() {
    int k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < s.length() / k; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < k; j++) {
                arr[i][j] = s[i * k + j];
            }
        }
        else {
            int c = k - 1;
            for (int j = 0; j < k; j++) {
                arr[i][j] = s[i * k + c];
                c--;
            }
        }
    }
    for (int i = 0; i < k; i++) for (int j = 0; j < s.length() / k; j++) cout << arr[j][i];
    return 0;
}