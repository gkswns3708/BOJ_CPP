#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1); // 아크코사인 값.
typedef complex<double> cpx; // 복잡한 계산을 할 때 (부동소수점 오차 등등) 도와줄 때 사용하는 library

vector<cpx> C;

void FFT(vector<cpx>& f, bool inv = false) {
	int n = f.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int b = n / 2;
		while (!((j ^= b) & b)) b /= 2;
		if (i < j) swap(f[i], f[j]);
	}
	for (int k = 1; k < n; k *= 2) {
		double a = (inv ? PI / k : -PI / k);
		cpx w(cos(a), sin(a));
		for (int i = 0; i < n; i += k * 2) {
			cpx wp(1, 0);
			for (int j = 0; j < k; ++j) {
				cpx x = f[i + j], y = f[i + j + k] * wp;
				f[i + j] = x + y;
				f[i + j + k] = x - y;
				wp *= w;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; ++i)
			f[i] /= n;
	}
}

void multiply(vector<cpx> a, vector<cpx> b) {
	int n = 1;
	while (n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	C.resize(n);

	FFT(a);
	FFT(b);
	for (int i = 0; i < n; ++i)
		C[i] = a[i] * b[i];
	FFT(C, true);
}


int main() {
	vector<cpx> A, B;
	while (1) {
		char c = getchar();
		if (c == ' ') break;
		A.push_back(cpx(c - '0', 0));
	} // string a input 받음.
	while (1) {
		char c = getchar();
		if (c == '\n') break;
		B.push_back(cpx(c - '0', 0));
	}// string b input 받음.
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	multiply(A, B);
	//FFT 를 적용해 A * B를 연산함.

	int carry = 0, i;
	vector<int> R;
	for (i = 0; i < C.size(); ++i) {
		int temp = (int)round(C[i].real()) + carry;
		R.push_back(temp % 10);
		carry = temp / 10;
	}
	while (carry > 0) {
		R.push_back(carry % 10);
		carry /= 10;
	}
	for (i = R.size() - 1; i >= 0 && R[i] == 0; --i) // 출력할 위치 결정.	
	if (i < 0) puts("0");
	else {
		for (; i >= 0; --i)
			putchar(R[i] + '0');
	}
}