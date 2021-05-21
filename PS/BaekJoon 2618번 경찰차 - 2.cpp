#include <iostream>
#include <vector>
#include <cstring>
#define X first
#define Y second
using namespace std;
struct police {
    int x1, y1, x2, y2;
};
int n, m, DP[1001][3], trace[1001][3]; //DP에는 이동거리, trace는 i를 확인할때 i-1까지 최소거리로 이동한 경찰차를 찾아 해당 번호를 저장하기 위한 배열입니다.
police car[1001][3]; //car에는 경찰차가 이동할때마다 좌표를 저장해줍니다.
vector<pair<int, int> > thief;

void print() {
    //DP[m]이 마지막 값이므로, DP[m][1], DP[m][2] 중 더 작은 값을 찾아 idx 변수에 담고, 
    //trace에 저장한 경찰차 번호를 역추적 해줍니다.
    int idx;
    if (DP[m][1] < DP[m][2]) {
        cout << DP[m][1] << '\n';
        idx = 1;
    }
    else {
        cout << DP[m][2] << '\n';
        idx = 2;
    }
    vector<int> ans; 
    for (int i = m; i > 0; i--) {
        ans.push_back(idx);
        idx = trace[i][idx];
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }
}

void dynamic() {
    for (int i = 1; i <= m; i++) {
        //x, y는 사건의 번호입니다.
        // fir이 붙은 변수는 1번 경찰차가 이동했을때의 1번, 2번 경찰차의 이전 좌표이고, sec이 붙은 변수는 2번 경찰차가 이동했을때의 1번, 2번 경찰차의 이전좌표입니다.
        // x1, y1은 1번 경찰차 x2, y2는 2번 경찰차입니다.
        int x = thief[i - 1].X, y = thief[i - 1].Y;
        int fir_x1 = car[i - 1][1].x1, fir_y1 = car[i - 1][1].y1, fir_x2 = car[i - 1][1].x2, fir_y2 = car[i - 1][1].y2;
        int sec_x1 = car[i - 1][2].x1, sec_y1 = car[i - 1][2].y1, sec_x2 = car[i - 1][2].x2, sec_y2 = car[i - 1][2].y2;
        // 아래는 1번 경찰차가 i번 사건을 맡을 경우와 2번 경찰차가 i번 사건을 확인할 경우를 전부 확인해 주는 과정입니다. 

        // 1번 경찰차가 i번 사건을 맡는 조건입니다. i-1번째 사건은 1번 경찰차가 해결했거나, 2번 경찰차가 해결했을 것이므로, 이 두가지 경우를 조건으로 넣어주었습니다.
        if (DP[i - 1][1] + abs(fir_x1 - x) + abs(fir_y1 - y) < DP[i - 1][2] + abs(sec_x1 - x) + abs(sec_y1 - y)) {
            trace[i][1] = 1;
            DP[i][1] = DP[i - 1][1] + abs(fir_x1 - x) + abs(fir_y1 - y);
            car[i][1].x1 = x, car[i][1].y1 = y, car[i][1].x2 = fir_x2, car[i][1].y2 = fir_y2;
        }
        else {
            trace[i][1] = 2;
            DP[i][1] = DP[i - 1][2] + abs(sec_x1 - x) + abs(sec_y1 - y);
            car[i][1].x1 = x, car[i][1].y1 = y, car[i][1].x2 = sec_x2, car[i][1].y2 = sec_y2;
        }
        // 2번 경찰차가 i번 사건을 맡는 조건입니다. 역시나 i-1번째 사건은 1번 경찰차가 해결했거나, 2번 경찰차가 해결했을 것이므로, 이 두가지 경우를 조건으로 넣어주었습니다.
        if (DP[i - 1][1] + abs(fir_x2 - x) + abs(fir_y2 - y) < DP[i - 1][2] + abs(sec_x2 - x) + abs(sec_y2 - y)) {
            trace[i][2] = 1;
            DP[i][2] = DP[i - 1][1] + abs(fir_x2 - x) + abs(fir_y2 - y);
            car[i][2].x2 = x, car[i][2].y2 = y, car[i][2].x1 = fir_x1, car[i][2].y1 = fir_y1;
        }
        else {
            trace[i][2] = 2;
            DP[i][2] = DP[i - 1][2] + abs(sec_x2 - x) + abs(sec_y2 - y);
            car[i][2].x2 = x, car[i][2].y2 = y, car[i][2].x1 = sec_x1, car[i][2].y1 = sec_y1;
        }
    }
}

void init() {
    memset(DP, 0, sizeof(DP));
    memset(trace, 0, sizeof(trace));
    memset(car, 0, sizeof(car));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        thief.push_back(make_pair(a, b));
    }
    //car는 경찰차가 이동할때마다 변하는 좌표를 저장하는데, 두개의 경찰차 시작좌표가 (1, 1) (n, n) 이므로 이것을 저장해주고 시작합니다.
    car[0][1].x1 = 1, car[0][1].y1 = 1, car[0][1].x2 = n, car[0][1].y2 = n;
    car[0][2].x1 = 1, car[0][2].y1 = 1, car[0][2].x2 = n, car[0][2].y2 = n;
}

int main() {
    init();
    dynamic();
    print();
}


/*
input:
11
30
5 5
1 1
1 11
5 5
1 1
1 3
2 1
1 3
2 1
1 3
11 11
2 4
4 2
3 3
5 5
3 3
1 1
9 3
9 3
3 9
3 9
3 3
11 1
3 3
1 1
3 3
5 9
5 9
10 3
10 3


123
2
1
1
2
2
2
2
2
2
2
1
2
2
2
1
2
2
1
1
2
2
2
1
2
2
2
2
2
1
1
*/
