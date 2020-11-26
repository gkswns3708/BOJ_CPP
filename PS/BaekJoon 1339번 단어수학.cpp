#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int ll;


int main() {
	int N; cin >> N;
	int num[26] = { 0, };
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			num[temp[j] - 'A'] += (int)pow(10, temp.length() - j - 1);
		}
	}
	sort(num, num + 26);
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += (9 - i) * num[25 - i];
	cout << ans;
	return 0;
}

