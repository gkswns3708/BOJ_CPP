#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

bool possible(int E,int EM,int M,int MH,int H,int mid) {
    // mid = ���� ������ ��ȸ�� ��.
    int e = E > mid ? 0 : mid - E; //EM���� �Ѿ ��ȸ �� 
    int h = H > mid ? 0 : mid - H; //MH�� �Ѿ ��ȸ ��
    int em = EM > e ? 0 :
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int E, EM, M, MH, H; cin >> E >> EM >> M >> MH >> H;
    int lo = 0, hi = 200000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (possible(E, EM, M, MH, H, mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}