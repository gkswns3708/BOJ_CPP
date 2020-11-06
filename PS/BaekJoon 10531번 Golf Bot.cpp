#include <bits/stdc++.h>
using namespace std;
typedef complex<double> C;
//a.size() must be 2^i
vector<int> ret(210000);
vector<int> a(210000);
int ans;
void fft(vector<C>& A, bool inv) {
    int n = A.size(), j = 0;
    vector<C> roots(n / 2);
    for (int i = 1; i < n; i++) {
        int bit = (n >> 1);
        while (j >= bit) j -= bit, bit >>= 1;
        j += bit;
        if (i < j) swap(A[i], A[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for (int i = 0; i < n / 2; i++) roots[i] = C(cos(ang * i), sin(ang * i));
    for (int i = 2; i <= n; i <<= 1) {
        int step = n / i;
        for (int j = 0; j < n; j += i) for (int k = 0; k < i / 2; k++) {
            C u = A[j + k], v = A[j + k + i / 2] * roots[step * k];
            A[j + k] = u + v;
            A[j + k + i / 2] = u - v;
        }
    }
    if (inv) for (int i = 0; i < n; i++) A[i] /= n;
}

void multiply(vector<int>& a, vector<int>& b) {
    vector<C> A(a.begin(), a.end()), B(b.begin(), b.end());
    int n = 2; while (n < (a.size() + b.size())) n <<= 1;
    A.resize(n); B.resize(n);
    fft(A, 0); fft(B, 0);
    for (int i = 0; i < n; i++) A[i] *= B[i];
    fft(A, 1);
    ret.resize(n);
    for (int i = 0; i < n; i++) ret[i] = (int)round(A[i].real());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    int maxvalue = 0;
    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;
        maxvalue = max(maxvalue, temp);
        a[temp] = 1;
    }
    a[0] = 1;
    multiply(a, a);
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        if (x <=maxvalue*2 && ret[x]!=0) ans++;
    }
    cout << ans;
    return 0;
}