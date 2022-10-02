#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;
#define _USE_MATH_DEFINES
typedef complex<double> base;
const int SIZE = 1 << 20; //50만보다 크면서 2의 거듭제곱 

void fft(vector<base>& a, bool invert) {
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

int n;
void multiply(vector<int>& a, vector<int>& res) {
    vector<base> fa(a.begin(), a.end());
    fft(fa, false);
    for (int i = 0; i < SIZE; i++) fa[i] *= fa[i];
    fft(fa, true);
    for (int i = 0; i < SIZE; i++) res[i % n] += int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> a(SIZE), res(SIZE), b(SIZE), c(SIZE);
    for (int i = 1; i <= n / 2; i++) {
        if (i != n - i) {
            a[i * i % n] += 2;
            c[2 * i * i % n] += 2;
        }
        else {
            a[i * i % n]++;
            c[2 * i * i % n]++;
        }
        b[i] = i * i % n;
    }
    multiply(a, res);
    int ans = 0, mu = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (i != n - i) ans += res[b[i]] * 2;
        else ans += res[b[i]];
    }
    for (int i = 1; i <= n / 2; i++) {
        if (i != n - i) mu += c[b[i]] * 2;
        else mu += c[b[i]];
    }
    ans = (ans - mu) / 2 + mu;
    cout << ans << "\n";
    return 0;
}