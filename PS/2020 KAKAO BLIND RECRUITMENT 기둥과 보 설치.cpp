#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;

bool checkbo(int n, int x, int y, int b) {
    if(b) { 
        bool onpi, left, right;
        onpi = left = right = false;
        for (auto nowinfo : answer) {
            //기둥위 확인
            if (nowinfo[2] == 0) {    
                if (x == nowinfo[0] && y == nowinfo[1]) onpi = true;
            }
            //양쪽이 다른 보와 연결인지 확인
            else {
                if (x == nowinfo[0] + 1 && y == nowinfo[1]) left = true;
                else if ((x + 1) == nowinfo[0] && y == nowinfo[1]) right = true;
            }
            if (onpi || (left && right)) return true;
        }
        return false;
    }
    else {

    }
}
bool checkpi(int n, int x, int y, int b) {

}

bool possible(int n,int x, int y, int a, int b) {
    if (a)
        return checkbo(n, x, y, b);
    else
        return checkpi(n, x, y, b);
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int cnt = 0;
    for (auto tp : build_frame) {
        int x, y, a, b;
        x = tp[0];y = tp[1];a = tp[2];b = tp[3];
        if (possible(n ,x, y, a, b)) {
            answer[cnt++].push_back(x);
            answer[cnt++].push_back(y);
            answer[cnt++].push_back(a);
        }
    }
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
