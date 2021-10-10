#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

int N, W;
int arr[2][10000 + 1];
bool visited[2][10000 + 1];

void input() {
    memset(arr, -1, sizeof arr);
    cin >> N >> W;
    for (int i = 0; i < 2; i++) for (int j = 0; j < N; j++) cin >> arr[i][j]; 
}

void solution() {

}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        input();
        solution();
    }
    return 0;
}