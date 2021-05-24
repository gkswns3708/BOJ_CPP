#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tiii tuple<double,int,int>
using namespace std;

double dist[100 + 1][100 + 1];
int parents[100 + 1];
vector<tiii> vec;
int _Find(int x) {
    return x == parents[x] ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
    a = _Find(a), b = _Find(b);
    a < b ? parents[b] = a : parents[a] = b;
}

int32_t main() {
    fastio;
    int N, cnt = 0; cin >> N;
    vector<pair<double, double>> pos(N);
    for (int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (i != j) {
                auto [x1, y1] = pos[i];
                auto [x2, y2] = pos[j];
                dist[i][j] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                vec.push_back({ dist[i][j],i,j });
            }
        }
    }
    for (int i = 0; i < N; i++) parents[i] = i;
    sort(vec.begin(), vec.end());
    double ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        auto [tmpdist, pos1, pos2] = vec[i];
        if (_Find(pos1) != _Find(pos2)) {
            _Union(pos1, pos2);
            ans += sqrt(tmpdist);
            if (++cnt == N - 1) break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}