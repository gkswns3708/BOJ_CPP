#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout.precision(15);
	cout << (double(a) / double(b));
	return 0;
}