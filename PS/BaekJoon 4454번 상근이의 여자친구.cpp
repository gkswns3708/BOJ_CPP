#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

double a, b, c, d, m, t;

double caloil(double a, double b, double c, double d, double v) {
    return (a * pow(v, 4) + b * pow(v, 3) + c * pow(v, 2) + d * v);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> a >> b >> c >> d >> m >> t) {
        double l = 0.0, r = 10000.0;
        for (int i = 0; i < 100; i++) {
            double v = (l + r) / 2.0;
            if (caloil(a, b, c, d, v) * m < v * t) l = v; //속도가 빠르면 
            else r = v;
        }
        r = floor(r * 100) / 100;
        cout << fixed << setprecision(2) << r << "\n";
    }
    return 0;
}