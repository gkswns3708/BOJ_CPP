#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
char buf[1 << 17];

inline char read() {
	static int idx = 1 << 17, nidx = 1 << 17;
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 17, stdin);
		if (!nidx) return 0;
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}
	return flg ? sum : -sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int arr[100000 + 1] = { 0, };
	int len = 0;
	int N = readInt();
	for (int i = 0; i < N; i++) {
		int val = readInt();
		int* pos = lower_bound(arr, arr + len, val);
		*pos = val;
		len += pos == arr + len;
	}

	cout << N - len << '\n';
	return 0;
}