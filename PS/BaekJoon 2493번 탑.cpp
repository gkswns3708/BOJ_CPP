#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

stack<pair<int, int>> stk;
vector<pair<int, int>> vec;
int ans[500000 + 1];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        vec.push_back({ temp,i });
    }
    for (int i = 0; i < N; i++) {
        if (stk.empty()) {
            stk.push(vec.back());
            vec.pop_back();
            continue;
        }
        while (1) {
            //¾ÆÁ÷ ¾È ¤±
            if (!stk.empty() && stk.top().first <= vec.back().first) {
                ans[stk.top().second] = vec.back().second;
                stk.pop();
            }
            else {
                stk.push(vec.back());
                vec.pop_back();
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}