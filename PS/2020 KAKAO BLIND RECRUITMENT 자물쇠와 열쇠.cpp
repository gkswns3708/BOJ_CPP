#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void rotate_R(vector<vector<int>>& key, vector<vector<int>> tempkey) {
    int m = key.size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            key[j][m - i - 1] = tempkey[i][j];
}

vector<vector<int>> initmap(int n,int m) {
    vector<vector<int>> tempvec(n+2*m-2);
    for (int i = 0; i < n + 2 * m - 2; i++) 
        tempvec[i].resize(n + 2 * m - 2);
    return tempvec;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    for (int rotate = 0; rotate < 4; rotate++) {
        for (int i = 0; i < m + n - 1; i++) for (int j = 0; j < m + n - 1; j++) {
            vector<vector<int>> mp = initmap(n, m);
            //mp에 key,lock붙이기
            for (int my = 0; my < m; my++) for (int mx = 0; mx < m; mx++) mp[i + my][j + mx] += key[my][mx];
            for (int ny = 0; ny < n; ny++) for (int nx = 0; nx < n; nx++) mp[m - 1 + ny][m - 1 + nx] += lock[ny][nx];
            
            bool check = true;

            for (int ty = m - 1; ty < m - 1 + n; ty++) {
                for (int tx = m - 1; tx < m - 1 + n; tx++) {
                    if (mp[ty][tx] == 1) continue;
                    else {check = false;break;}
                }
            }
            if (check) return true;
        }

        rotate_R(key,key);
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> key(3), lock(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp; cin >> temp;
            key[i].push_back(temp);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp; cin >> temp;
            lock[i].push_back(temp);
        }
    }
    cout << solution(key, lock);
    return 0;
}
