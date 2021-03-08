#include <bits/stdc++.h>
#pragma warning(disable:4996)
#define INF 987654321
#define int long long int
#define X first
#define Y second
#define MOD (int)1e9+7
using namespace std;
using tiii = tuple<int, int, int>;
using pii = pair<int, int>;
int N;
bool arr[8] = { 0,1, 0,1,1,1,1 };
void input() {
	cin >> N;
}


void solution() {
	arr[N % 7] == 1 ? cout << "SK" : cout << "CY";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solution();
	return 0;
}