#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int Land[101];
int D[101][101];
int check[16384][101];
queue<pair<int, int>> q;
pair<int, int>p;


int main() {
    memset(Land, -1, sizeof(Land)); //보석이 있는 섬이면 0이상의 값, 없으면 -1
    memset(D, -1, sizeof(D)); // 다리
    memset(check, -1, sizeof(check)); // 지금 좌표에서 가질 수 있는 최대 보석의 수
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int z;
        cin >> z;
        Land[z - 1] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        D[a - 1][b - 1] = c;
        D[b - 1][a - 1] = c;
    }
    check[0][0] = 0;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        p = q.front(); q.pop();
        int key = p.first; //보석을 주운 섬의 번호들
        int x = p.second; // 현재 위치
        if (x == 0) ans = max(check[key][x], ans); // 0번 섬에 왔으면 ans 최대값을 갱신함
        if (Land[x] != -1 && !(key & 1 << Land[x])) { //x섬에 보석이 있는데 그동안 줍지 않았을 경우
            int nkey = key | 1 << Land[x];
            if (check[nkey][x] < check[key][x] + 1) {
                check[nkey][x] = check[key][x] + 1;
                q.push(make_pair(nkey, x));
            }
        }
        for (int i = 0; i < n; i++) { // for문을 이용해 x번 섬에서 nx번 섬으로 이동할 곳이 있는지 확인
            int nx = i;
            int Max = D[x][i];
            if (check[key][x] <= Max && check[key][nx] < check[key][x]) {
                check[key][nx] = check[key][x];
                q.push(make_pair(key, nx));
            }
        }
    }
    cout << ans << endl;
}