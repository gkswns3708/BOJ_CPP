#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

map<int, int> color_trans;
bool visited[100 + 1][100 + 1] = { 0, };
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool possible(int y, int x, vector<vector<int>>& picture, int m, int n) {
    if (y >= 0 && y < m && x >= 0 && x < n && !visited[y][x] && picture[y][x] != 0) return true;
    else return false;
}


int bfs(int y, int x, vector<vector<int>>& picture, int m, int n) {
    queue<pair<int, int>> que;
    int now_color = picture[y][x];
    visited[y][x] = 1;
    que.push({ y,x });
    int ret = 0;
    while (!que.empty()) {
        auto [ny, nx] = que.front();
        que.pop();
        ret++;
        for (int i = 0; i < 4; i++) {
            int next_y = ny + dy[i];
            int next_x = nx + dx[i];
            if (possible(next_y, next_x, picture, m, n) && now_color == picture[next_y][next_x]) {
                que.push({ next_y, next_x });
                visited[next_y][next_x] = 1;
            }
        }
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < 100; i++) {
        memset(visited[i], 0, sizeof(visited[i]));
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    int color_cnt = 0;
    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
            if (picture[i][j] != 0 && color_trans.find(picture[i][j]) == color_trans.end())
                color_trans[picture[i][j]] = ++color_cnt;
        }
    }


    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
            if (possible(i, j, picture, m, n)) {
                answer[1] = max(answer[1], bfs(i, j, picture, m, n));
                answer[0]++;
            }
        }
    }


    return answer;
}

int main() {
    for (auto& now : solution(6, 4, { {1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3} })) {
        cout << now << "\n";
    }
}