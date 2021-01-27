#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int A = 0x11000111;
	int b = 0x01000111;
	int c = A ^ b;
	cout << c;
	return 0;
}