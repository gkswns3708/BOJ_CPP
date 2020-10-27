////1003번 피보나치 함수
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <list>
typedef long long int ll;
using namespace std;
ll visitleftup[40 + 1];
ll fibonacci(int n) {
	if (n == 1 || n == 2) {
		visitleftup[n] = 1;
		return 1;
	}
	else if (n == 0) {
		visitleftup[n] = 0;
		return 0;
	}
	if (visitleftup[n] != 0) {
		return visitleftup[n];
	}
	else visitleftup[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return visitleftup[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TC;
	cin >> TC;
	while (TC--) {
		int num;
		cin >> num;
		if (num == 0) {
			cout << 1 << " " << 0 << "\n";
		}
		else if (num == 1) {
			cout << 0 << " " << 1 << "\n";
		}
		else cout << fibonacci(num - 1) << " " << fibonacci(num) << "\n";
	}
	return 0;
}