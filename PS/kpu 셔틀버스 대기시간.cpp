#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;
int N, M, C;
vector<int> vec;

bool possible(int mid) {
    int firststudent = -1;
    int bus = 0, cnt = 0; // bus = 총 버스, cnt는 버스에 타 있는 학생 수
    for (int i = 0; i < N; i++) {
        if (cnt == C) {
            bus++;
            cnt = 0;
            firststudent = -1;
            i--;
            continue;
        }
        else {
            if (cnt == 0) {
                firststudent = vec[i];
                cnt++;
            }
            else {
                if (vec[i] - firststudent > mid) {
                    firststudent = vec[i];
                    bus++;
                    cnt = 1;
                }
                else {
                    cnt++;
                }
            }
        }
    }

    bus += (cnt != 0 ? 1 : 0);
    return bus <= M;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> C;
    vec.resize(N);
    for (int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    int l = 0, r = int(1e9 + 1);
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (possible(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
    return 0;
}