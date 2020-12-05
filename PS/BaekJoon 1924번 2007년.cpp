#include <bits/stdc++.h>
using namespace std;

int main() {
	int Month[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string s[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int month, day, nowday = 0; cin >> month >> day;
	for (int i = 0; i < month-1; i++) nowday += Month[i];
	nowday += day;
	cout << s[nowday % 7];
	return 0;
}