#include <iostream>
#include <vector>
#include <cstring>
#define X first
#define Y second
using namespace std;
struct police {
    int x1, y1, x2, y2;
};
int n, m, DP[1001][3], trace[1001][3]; //DP���� �̵��Ÿ�, trace�� i�� Ȯ���Ҷ� i-1���� �ּҰŸ��� �̵��� �������� ã�� �ش� ��ȣ�� �����ϱ� ���� �迭�Դϴ�.
police car[1001][3]; //car���� �������� �̵��Ҷ����� ��ǥ�� �������ݴϴ�.
vector<pair<int, int> > thief;

void print() {
    //DP[m]�� ������ ���̹Ƿ�, DP[m][1], DP[m][2] �� �� ���� ���� ã�� idx ������ ���, 
    //trace�� ������ ������ ��ȣ�� ������ ���ݴϴ�.
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
        //x, y�� ����� ��ȣ�Դϴ�.
        // fir�� ���� ������ 1�� �������� �̵��������� 1��, 2�� �������� ���� ��ǥ�̰�, sec�� ���� ������ 2�� �������� �̵��������� 1��, 2�� �������� ������ǥ�Դϴ�.
        // x1, y1�� 1�� ������ x2, y2�� 2�� �������Դϴ�.
        int x = thief[i - 1].X, y = thief[i - 1].Y;
        int fir_x1 = car[i - 1][1].x1, fir_y1 = car[i - 1][1].y1, fir_x2 = car[i - 1][1].x2, fir_y2 = car[i - 1][1].y2;
        int sec_x1 = car[i - 1][2].x1, sec_y1 = car[i - 1][2].y1, sec_x2 = car[i - 1][2].x2, sec_y2 = car[i - 1][2].y2;
        // �Ʒ��� 1�� �������� i�� ����� ���� ���� 2�� �������� i�� ����� Ȯ���� ��츦 ���� Ȯ���� �ִ� �����Դϴ�. 

        // 1�� �������� i�� ����� �ô� �����Դϴ�. i-1��° ����� 1�� �������� �ذ��߰ų�, 2�� �������� �ذ����� ���̹Ƿ�, �� �ΰ��� ��츦 �������� �־��־����ϴ�.
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
        // 2�� �������� i�� ����� �ô� �����Դϴ�. ���ó� i-1��° ����� 1�� �������� �ذ��߰ų�, 2�� �������� �ذ����� ���̹Ƿ�, �� �ΰ��� ��츦 �������� �־��־����ϴ�.
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
    //car�� �������� �̵��Ҷ����� ���ϴ� ��ǥ�� �����ϴµ�, �ΰ��� ������ ������ǥ�� (1, 1) (n, n) �̹Ƿ� �̰��� �������ְ� �����մϴ�.
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
