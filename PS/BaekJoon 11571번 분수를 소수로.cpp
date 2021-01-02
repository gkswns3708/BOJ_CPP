#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int arr[100000 + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int num1, num2, gcdvalue, k = 0; cin >> num1 >> num2;
		gcdvalue = gcd(num1, num2);
		num1 /= gcdvalue; num2 /= gcdvalue;
		int s, f; s = f = 0;
		
		memset(arr, -1, sizeof(arr));

		int temp = num1 % num2*10;
		cout << num1 / num2 <<".";
		while (1) {
			num1 = num1 % num2 * 10;
			if (arr[num1] != -1) {
				s = arr[num1];
				f = k; 
				break;
			}
			arr[num1] = k++;
		}
		for (int i = 0; i < s; i++) {
			cout << temp / num2;
			temp = temp % num2 * 10;
		}
		cout << "(";
		for (int i = s; i < f; i++) {
			cout << temp / num2;
			temp = temp % num2 * 10;
		}
		cout << ")\n";
	}
	return 0;
}