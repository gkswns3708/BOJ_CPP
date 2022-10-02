#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
const int MAX_V = 61010;
using namespace std;
typedef complex<double> base;
void FFT(vector<base>& a, bool invert) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double x = 2 * M_PI / len * (invert ? -1 : 1);
        base wlen(cos(x), sin(x));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }

    }
    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}


vector<base> multiply(vector<base>& v, vector<base>& u) {
    int SZ = 2;
    while (SZ < v.size() + u.size()) SZ <<= 1;

    v.resize(SZ); FFT(v, false);
    u.resize(SZ); FFT(u, false);
    vector<base> tmp(SZ);
    for (int i = 0; i < SZ; i++) tmp[i] = v[i] * u[i];
    FFT(tmp, true);
    return tmp;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<base> v(MAX_V), u(MAX_V), w(MAX_V);

    int N; cin >> N;
    while (N--) {
        int x; cin >> x;
        v[x + 30000] = base(1, 0);
    }
    int M; cin >> M;
    while (M--) {
        int x; cin >> x;
        u[x + 30000] = base(1, 0);
    }
    int K; cin >> K;
    while (K--) {
        int x; cin >> x;
        w[x + 30000] = base(1, 0);
    }

    vector<base> vw = multiply(v, w);

    int ans = 0;
    for (int i = 0; i <= 60000; i++) {
        ans += round(u[i].real()) * round(vw[i * 2].real());
    }
    cout << ans << "\n";

    return 0;
}