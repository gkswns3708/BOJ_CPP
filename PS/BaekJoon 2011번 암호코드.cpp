#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000
int dp[5000 + 9];

int main(void) {
	string s; cin >> s;
	int size = s.length();
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= size; i++) {
		if (s[i - 1] > '0')dp[i] = dp[i - 1];
		int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
		if (10 <= num && num <= 26)	dp[i] = (dp[i] + dp[i - 2]) % mod;
	}
	if (s[0] == '0') dp[size] = 0;
	cout << dp[size];
	return 0;
}