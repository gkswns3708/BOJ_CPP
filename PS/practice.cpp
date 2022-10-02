#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;
typedef complex<double> cpx;
const double PI = acos(-1);

void FFT(vector<cpx>& a, bool inv) {
    int S = a.size();

    for (int i = 1, j = 0; i < S; i++) {
        int bit = S / 2;

        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if (i < j) swap(a[i], a[j]);
    }

    for (int k = 1; k < S; k *= 2) {
        double angle = (inv ? PI / k : -PI / k);
        cpx w(cos(angle), sin(angle));
        for (int i = 0; i < S; i += k * 2) {
            cpx z(1, 0);

            for (int j = 0; j < k; j++) {
                cpx even = a[i + j];
                cpx odd = a[i + j + k];

                a[i + j] = even + z * odd;
                a[i + j + k] = even - z * odd;
                z *= w;
            }

        }
    }
    if (inv) for (int i = 0; i < S; i++) a[i] /= S;
}

vector<int> mul(vector<int>& v, vector<int>& u) {
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    int S = 2;
    while (S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);


    for (int i = 0; i < S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vector<int> w(S);
    for (int i = 0; i < S; i++) if (round(vc[i].real()) != 0) w[i] = 1;

    return w;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int> v(1024);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        v[x] = 1;
    }

    vector<int> u(1, 1);
    while (K > 0) {
        if (K & 1) u = mul(u, v);

        v = mul(v, v);
        K /= 2;
    }
    for (int i = 0; i < u.size(); i++)if (u[i] != 0) cout << i << " ";

    cout << "\n";
    return 0;
}