#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>
int n, m;
vi parent;

int Find(int x) {
    return parent[x] == x ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    parent[Find(b)] = Find(a);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        parent = vi(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            if (Find(x) != Find(y)) Union(x, y), ans += 1;
            else ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}